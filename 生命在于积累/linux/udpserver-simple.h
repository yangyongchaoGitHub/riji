#ifndef _UDPSERVER_H
#define _UDPSERVER_H

#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

class UDPServer 
{
public:
    UDPServer();
    void init();
private:
    pthread_t thread_server;
    int server_df;
    void listener(struct sockaddr_in *target);
};
