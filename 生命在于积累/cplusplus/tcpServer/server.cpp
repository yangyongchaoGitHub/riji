#include "server.h"

int testnum = 10000;
mutex mu;  //线程互斥对象

void Server::test() {

    cout << "testest";
}

void thread_s1 () {
    std::thread::id tid = std::this_thread::get_id();
    for (int i = 0; ; i++) {
        //lock_guard<mutex> lockGuard(mu); 这种方式的锁相对较慢 但是安全
        mu.lock();
        cout << "aiee thread_s1 " << tid << " " << testnum-- << endl;
        mu.unlock();
        Sleep(100);
    }
}

void addClient (SOCKET sockConn, SOCKADDR_IN addrClient) {
    char sendBuf[50];
    sprintf(sendBuf,"Welcome %s to here!",inet_ntoa(addrClient.sin_addr));//inet_ntoa网络地址转换转点分十进制的字符串指针
    send(sockConn,sendBuf,strlen(sendBuf)+1,0);

    while(1) {
        char recvBuf[50];
        int rec = recv(sockConn, recvBuf,50,0);
        printf("%s %i\n", recvBuf, rec);
        cout << "111" << endl;
    }
}

void Server::start() {
    wVersionRequested = MAKEWORD( 1, 1 );//第一个参数为低位字节；第二个参数为高位字节

    err = WSAStartup( wVersionRequested, &wsaData );//对winsock DLL（动态链接库文件）进行初始化，协商Winsock的版本支持，并分配必要的资源。
    if ( err != 0 )
    {
        cout << "WSAStartup error ";
        return;
    }

    if ( LOBYTE( wsaData.wVersion ) != 1 ||HIBYTE( wsaData.wVersion ) != 1 )//LOBYTE（）取得16进制数最低位；HIBYTE（）取得16进制数最高（最左边）那个字节的内容
    {
        cout << "wVersion error ";
        WSACleanup( );
        return;
    }

    SOCKET sockSrv=socket(AF_INET,SOCK_STREAM,0);//创建socket。AF_INET表示在Internet中通信；SOCK_STREAM表示socket是流套接字，对应tcp；0指定网络协议为TCP/IP
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY); //htonl用来将主机字节顺序转换为网络字节顺序(to network long)
    //INADDR_ANY就是指定地址为0.0.0.0的地址,
    //表示不确定地址,或“任意地址”。”
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(4000);//htons用来将主机字节顺序转换为网络字节顺序(to network short)

    bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//将本地地址绑定到所创建的socket上，以使在网络上标识该socket

    listen(sockSrv,5);//socket监听，准备接受连接请求。

    SOCKADDR_IN addrClient;
    int len=sizeof(SOCKADDR);

    while(1)
    {
        SOCKET sockConn=accept(sockSrv,(SOCKADDR*)&addrClient,&len);//为一个连接请求提供服务。addrClient包含了发出连接请求的客户机IP地址信息；返回的新socket描述服务器与该客户机的连接

        //创建客户端线程
        thread t(addClient, sockConn, addrClient);
        t.detach();

        //closesocket(sockConn);
        //Sleep(2000);//2000毫秒
    }
    WSACleanup();
}
