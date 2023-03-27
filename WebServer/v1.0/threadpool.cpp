#include "threadpool.h"

threadpool_t *threadpool_create(int thread_count,int queue_size,int flags){
       threadpool_t *pool;
       int i;
       //(void) flags;
       do{
        if(thread_count<=0||thread_count> MAX_THREADS ||queue_size<=0||queue_size>MAX_QUEUE){
            return NULL;
        }  

        if((pool=(threadpool_t *)malloc(sizeof(threadpool_t)))==NULL){
            break;
        }

        /*Initialize */
        pool->thread_count=0;
        pool->queue_size=queue_size;
        pool->head=pool->tail=pool->count=0;
        pool->shutdown=pool->started=0;

        /*Allocate thread and task queue */
        pool->threads=(pthread_t *)malloc(sizeof(pthread_t) * thread_count);
        pool->queue=(threadpool_task_t *)malloc(sizeof(threadpool_task_t) * queue_size);

        /*Initialize mutex and conditional variable first*/
        if((pthread_mutex_init(&(pool->lock),NULL)!=0)||
           (pthread_cond_init(&(pool->notify),NULL)!=0)||
           (pool->threads==NULL)||
           (pool->queue==NULL))
        {
            break;
        }

        /*Start worker threads */
        for(i=0;i<thread_count;i++){
            if(pthread_create(&(pool->threads[i]), NULL, threadpool_thread,(void*)pool)!=0){
                threadpool_destory(pool,0);
                return NULL;
            }
            pool->thread_count++;
            pool->started++;
        }

        return pool;

       }while(false);

        if (pool != NULL){
            threadpool_free(pool);
        }
        return NULL;

}  

int threadpool_add(threadpool_t *pool,void (*function)(void *),void *argument,int flags){
    //printf("add to thread pool!\n")
    int err=0;
    int next;
    //(void) flags
    if (pool==NULL||function ==NULL){
        return THREADPOOL_INVALID;
    }
    if (pthread_mutex_lock(&(pool->lock))!=0){
        return THREADPOOL_LOCK_FAILURE;
    }
    next=(pool->tail+1)%pool->queue_size;
    do{
        /*Are we full? */
        if(pool->count==pool->queue_size){
            err=THREADPOOL_SHUTDOWN;
            break;
        }
        /*Add task to queue */
        pool->queue[pool->tail].function=function;
        pool->queue[pool->tail].argument=argument;
        pool->tail=next;
        pool->count+=1;

        /*pthread_cond_broadcast */
        if(pthread_cond_signal(&(pool->notify))!=0){
            err=THREADPOOL_LOCK_FAILURE;
            break;
        }
    }while(false);

    if(pthread_mutex_unlock(&pool->lock)!=0){  //TODO (&pool->lock)和(&(pool->lock))的区别？
        err =THREADPOOL_LOCK_FAILURE;
    }

    return err;
}

int threadpool_destory(threadpool_t *pool,int flags){
    printf("Thread pool destory! \n");
    int i,err=0;
    if (pool==NULL){
        return THREADPOOL_INVALID;
    }

    if(pthread_mutex_lock(&(pool->lock))!=0){
        return THREADPOOL_LOCK_FAILURE;
    }

    do{
        /*Already shutting down */
        if(pool->shutdown){
            err=THREADPOOL_SHUTDOWN;
            break;
        }

        pool->shutdown=(flags & THREADPOOL_GRACEFUL)?graceful_shutdown:immediate_shutdown;

        /*Wake up all worker threads */
        if((pthread_cond_broadcast(&(pool->notify))!=0)||
           (pthread_mutex_unlock(&(pool->lock))!=0)
          ){
            err =THREADPOOL_LOCK_FAILURE;
            break;
        }

        /*Join all worker thread */
        for(i=0;i<pool->thread_count;i++){
            if(pthread_join(pool->threads[i],NULL)!=0){
                err=THREADPOOL_THREAD_FAILURE;
            }
        }
    }while(false); 

    /*Only if everything went well do we deallocate the pool */
    if(!err){
        threadpool_free(pool);
    }
    return err;
}

int threadpool_free(threadpool_t *pool){
    if(pool->threads){
        free(pool->threads);
        free(pool->queue);

        /*Because we allocate pool->threads after initializing the
            mutex and condition variable, we're sure they're
            initialized.Let's lock the mutex just in case.*/
        pthread_mutex_lock(&(pool->lock));
        pthread_mutex_destroy(&(pool->lock));
        pthread_cond_destroy(&(pool->notify));
    }
    free(pool);
    return 0;
}

static void *threadpool_thread(void *threadpool){
    threadpool_t *pool =(threadpool_t *)threadpool;
    threadpool_task_t task;

    for(;;){
        /*Lock must be taken to wait on conditional variable */
        pthread_mutex_lock(&(pool->lock));

        /* Wait on condition variable, check for spurious wakeups.
           When returning from pthread_cond_wait(), we own the lock. */
        while((pool->count==0)&&(!pool->shutdown)){
            pthread_cond_wait(&(pool->notify),&(pool->lock));
        }

        if((pool->shutdown==immediate_shutdown)||
           ((pool->shutdown==graceful_shutdown)&&(pool->count==0))
          ){
            break;
        }

        /*Grab out task */
        task.function=pool->queue[pool->head].function;
        task.argument=pool->queue[pool->head].argument;
        pool->head=(pool->head+1)%pool->queue_size;
        pool->count-=1;

        /*Unlock */
        pthread_mutex_unlock(&(pool->lock));

        /*Get to work */
        (*(task.function))(task.argument);
    }

    --pool->started;

    pthread_mutex_unlock(&(pool->lock));
    pthread_exit(NULL);
    return NULL;

}



/*
*注释：
    @pthread_cond_t
    条件变量是线程可用的另一种同步机制。条件变量给多个线程提供了一个会合的场所
    条件变量与互斥量一起使用时，允许线程以无竞争的方式等待特定的条件发生
    条件变量要与互斥量一起使用，条件本身是由互斥量保护的。线程在改变条件状态之前必须首先锁住互斥量
    其他线程在获得互斥量之前不会察觉到这种改变，因为互斥量必须在锁定以后才能计算条件

    @pthread_mutex_init
    函数原型如下：int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    linux下为了多线程同步，通常用到锁的概念。posix下抽象了一个锁类型的结构：pthread_mutex_t，通过对
该结构的操作来判断资源是否可以访问。
    pthread_mutex_init()函数以动态方式创建互斥锁，互斥锁的属性由参数altr在创建锁的时候指定/如果参数attr为空(NULL)，
则使用默认的互斥锁属性，默认属性为快速互斥锁。
    pthread_mutexattr_init() 函数成功完成之后会返回零，其他任何返回值都表示出现了错误。

    @restrict
    restrict用于限定和约束指针，通过加上restrict关键字，编程者可提示编译器：在该指针的生命周期内，其指向的对象不会被别的指针所引用。
    https://developer.aliyun.com/article/951221

    @pthread_cond_init
    pthread_cond_init是一个用来初始化条件变量的函数
    

    @pthread_cond_signal
    pthread_cond_signal函数的作用是发送一个信号给另外一个正在处于阻塞等待状态的线程。使其脱离阻塞状态继续执行。
如果没有线程处在阻塞等待状态，pthread_cond_signal也会成功返回
    pthread_cond_signal()至少解除一个某个条件变量上阻塞的线程的阻塞，如果有任何线程阻塞在条件变量上的话。

    @pthread_cond_broadcast
    pthread_cond_broadcast(&cond1)的作用是唤醒所有正在pthread_cond_wait(&cond1,&mutex1)的线程
    pthread_cond_signal(&cond1)的作用是唤醒所有正在pthread_cond_wait(&cond1,&mutex1)的至少一个线程。

    @pthread_cond_wait
    pthread_cond_wait用于阻塞当前线程，等待别的线程使用pthread_cond_signal或者pthread_cond_broadcast来
唤醒它。pthread_cond_wait必须与pthread_mutex配套使用。
    pthread_cond_wait()函数一进入wait状态就会自动release mutex。当其他线程通过pthread_cond_signal或者pthread_cond_broadcast
把该线程唤醒，使pthread_cond_wait()通过(返回)时，该线程又自动获得该mutex


*/