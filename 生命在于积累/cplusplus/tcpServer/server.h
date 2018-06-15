#ifndef SERVER
#define SERVER
#include <iostream>
#include <WinSock2.h>
#include <thread>
#include <stdio.h>
#include <mutex>

using namespace std;

class Server
{
public :

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    void test();
    void start();
};
#endif // SERVER

