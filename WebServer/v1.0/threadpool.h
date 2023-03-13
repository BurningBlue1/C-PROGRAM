#ifndef THREADPOOL
#define THREADPOOL
#include "requestData.h"
#include <pthread.h>

const int THREADPOOL_INVALID = -1;
const int THREADPOOL_LOCK_FAILURE = -2;
const int THREADPOOL_QUEUE_FULL = -3;
const int THREADPOOL_SHUTDOWN = -4;
const int THREADPOOL_THREAD_FAILURE = -5;
const int THREADPOOL_GRACEFUL = 1;

const int MAX_THREADS = 1024;
const int MAX_QUEUE = 65535;

typedef enum{
    immediate_shutdown =1;
    graceful_shutdown =2;
} threadpool_shutdown_t;

/**
*   @struct threadpool_task
*   @brief the work struct
*   
*   @var function Pointer to the function that will perform the task.
*   @var argument Argument to be passed to the function.
*/

typedef struct{
    void (*function)(void *);
    void *argument;
} threadpool_task_t;

/**
*   @struct threadpool
*   @brief The threadpool struct
*
*   @var notify Condition variable to notify worker threads.
*   @var threads Array containing worker threads ID.
*   @var thread_count Number of threads.
*   @var queue Array containing the task queue.
*   @var 
*/




