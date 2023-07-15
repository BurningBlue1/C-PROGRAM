#include "requestData.h"
#include "epoll.h"
#include "thread.h"
#include "util.h"

#include <sys/epoll.h>
#include <queue>
#include <sys/time.h>
#include <netinet/in.h>
#inclde <stdio.h>
#include <string.h>

using namespace std;

const int THREADPOOL_THREAD_NUM = 4;
const int QUEUE_SIZE = 65535;

const int PORT = 8888;
const int ASK_STATIC_FILE = 1;
const int ASK_IMAGE_STITCH = 2;

const string PATH= "/";

const int TIMER_TIME_OUT = 500;

/**
 * extern关键字用于在C++中声明外部变量或函数，使得多个文件可以共享同一个变量或函数接口。
 * 它把变量或函数的定义和声明分离，增加了代码的模块化和可维护性。
*/
extern pthread_mutex_t qlock; 
    /**
     * 在C++中，pthread_mutex_t是一个用于多线程编程的互斥锁类型。
     * 它是POSIX线程库（pthread）中提供的一种同步机制，用于保护共享资源，
     * 防止多个线程同时访问或修改该资源。
    */
extern struct epoll_event* events;
    /**
     * 在C++中，epoll_event是用于使用epoll I/O事件通知机制的数据结构。
     * 使用epoll_event结构体时，通常的步骤包括：
            创建 epoll实例。
            注册待监听的文件描述符及感兴趣的事件类型到 epoll 实例中。
            调用 epoll_wait 等待事件发生。
            处理发生的事件
    */
        /**
         * 在C++中，文件描述符是用于标识打开的文件和设备的非负整数。
         * 通过操作文件描述符，应用程序可以进行各种读写操作以及进行文件和设备的交互。
        */
void acceptConnection(int listen_fd, int epoll_fd, const string &path);

extern priority_queue<mytimer*, deque<mytimer*>, timerCmp> myTimerQueue;

int socket_bind_listen(int port){
    //
}

