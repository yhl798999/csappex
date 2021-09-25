#include "csapp.h"
#include "testfun.h"
// 接收客户端发送的字符串，将其转换为指定格式（小写或大写）并返回转换的字符串

void sigchild_handler(int sig)
{
    while (waitpid(-1, 0, WNOHANG) > 0)
        ;
    return;    
}

// complicated by process
int complicate_by_process(int port)
{
    int listen_fd = open_listenfd(port);
    if(listen_fd < 0)
    {
        printf("failed to listen %d", port);
        return 1;
    }

    int connfd;
    struct sockaddr_in addr;
    socklen_t addrlen;

    signal(SIGCHLD, sigchild_handler);

    while((connfd = accept(listen_fd, (struct sockaddr*)&addr, &addrlen)) >= 0)
    {
        if(fork() == 0)
        {
            close(listen_fd);
            transform(connfd);
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
}