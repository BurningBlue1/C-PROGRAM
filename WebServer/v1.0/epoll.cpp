#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<assert.h>
#include<sys/epoll.h>


// #include "epoll.h"
// #include<iostream>
// #include <sys/epoll.h>
// #include <errno.h>
// #include "threadpool.h"

struct epoll_event* events;

int epoll_init(){
    int epoll_fd=epoll_create(LISTENQ+1);

}

