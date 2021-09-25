#include "testfun.h"
#include "stdio.h"
#include "csapp.h"

void to_upper(char*str, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

void to_lower(char*str, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}

void transform(int fd)
{
    int m;
    int len;
    char buf[MAXLINE];
    rio_t rio_rt;
    rio_readinitb(&rio_rt, fd);
    
    len = rio_readlineb(&rio_rt, buf, MAXLINE);
    m = strcmp("upper", buf);
    if(m && strcmp("lower", buf))
    {
        printf("error conn");
        return 1;
    }

    while ((len = rio_readlineb(&rio_rt, buf, MAXLINE)) > 0)
    {
        rio_writen(fd, buf, len);
    }
}