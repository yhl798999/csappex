#include "csapp.h"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage: %s portno\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int listenfd = open_listenfd(port);
    if(listenfd < 0)
    {
        printf("failed to listen %d\n", port);
        return 1;
    }

    printf("begin listen to %d...\n", port);

    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int connfd;
    char buf[128];
    while((connfd = accept(listenfd, (struct sockaddr*)&addr, &addrlen)) >= 0)
    {
        printf("connect to %s", inet_ntoa(addr.sin_addr));
        FILE* file = popen("date","r");
        bzero(&buf, sizeof(buf));
        fread(&buf, 128, 1, file);
        write(connfd, buf, 128);
        close(connfd);
    }

    printf("stop listen\n");
    return 0;
}