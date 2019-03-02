#include "udpserver.h"

typedef struct {
    int id; 
    int status;
}TBilateral;


UDPServer::UDPServer()
{}

void UDPServer::listener()
{
    char buf[1024];
    socklen_t len;
    int count = 0;
    struct sockaddr_in clent_addr, ser_addr;
    TBilateral local_blt;

    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = inet_addr("192.168.0.89");
    ser_addr.sin_port = htons(3213);

    //sprintf(buf, "first send!!!", count);
    memset(&local_blt, 0, sizeof(TBilateral));

    len = sizeof(ser_addr);
    memcpy(&buf, &local_blt, sizeof(TBilateral));
    sendto(server_df, buf, 1024, 0, (struct sockaddr*)&ser_addr, len);

    while(1) {
        memset(buf, 0, sizeof(1024));
        len = sizeof(clent_addr);
        count = recvfrom(server_df, buf, 1024, 0, (struct sockaddr*)&clent_addr, &len);
if (count == -1) {
            printf("recver data fail!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! return listen thread\n");
            return;
        }

        memcpy(&local_blt, buf, sizeof(TBilateral));
        printf("client recv data blt.id%d, status:%d clientIP:%s \n", local_blt.id, local_blt.status, inet_ntoa(clent_addr.sin_addr));

        sleep(5);
        memset(buf, 0, 1024);
        local_blt.status = local_blt.status + 1;
        //sprintf(buf, "3 sendmsg!!!  ", count);

        memcpy(&buf, &local_blt, sizeof(TBilateral));

        sendto(server_df, buf, 1024, 0, (struct sockaddr*)&clent_addr, len);

    }
}

void UDPServer::init()
{
    int err, ret;
    struct sockaddr_in ser_local;

    server_df = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_df < 0) {
        printf("create socke fail!!! \n");
        return;
    }

    memset(&ser_local, 0, sizeof(ser_local));
ser_local.sin_family = AF_INET;
    ser_local.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_local.sin_port = htons(3213);

    ret = bind(server_df, (struct sockaddr *)&ser_local, sizeof(ser_local));

    if (ret < 0) {
        printf("socket bind fail \n");
    }

    listener();
#if 0
    thread_server = 0;
    err = pthread_create(&thread_server, NULL, [](void *arg){
            ((UDPServer*)arg)->listener();
            return (void*)NULL;
            }, this);
    if (err || !thread_server) {
        printf("pthread_create error!!1 \n");
    }
#endif
}

int main(int argc, char *argv[])
{
    printf("this set target addr is 89\n");
    UDPServer *server = new UDPServer();
    server->init();
}
