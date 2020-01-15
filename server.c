/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#include "wrap.h"
#include "user_info.h"
#include "send_message.h"

struct Th_parameter    //用以给线程传递文件描述符和网络信息
{
    int connfd;
    struct sockaddr_in cliaddr;
};

#define USERLEN 20
#define MAXLINE 80
#define SERV_PORT 8000

/*线程用于与某一客户端实现对接完成功能*/
void *th_server(void *parameter)
{
    char message_receive[MAXLINE];
    char str[INET_ADDRSTRLEN];
    char username[USERLEN];
    char target_user[USERLEN];
    int i, n;
    //接收来自主函数的参数
    int connfd = ((struct Th_parameter *)parameter)->connfd;
    struct sockaddr_in cliaddr = ((struct Th_parameter *)parameter)->cliaddr;

    //从客户端获取服务客户端的用户名
    n = Read(connfd, username, USERLEN);
    username[n] = '\0';
    add_user(username, connfd);  //获得用户名并与文件描述符对应插入链表
    
    while (1)
    {
        n = Read(connfd, message_receive, MAXLINE);
        if (n == 0)
        {
            printf("the other side has been closed.\n");
            break;
        }
        //将从客户端读到的信息转换为字符串
        message_receive[n] = '\0';
        printf("received from %s at PORT %d\n",
                inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                ntohs(cliaddr.sin_port));

        if(strcmp(message_receive, "mode\n") == 0)
        {
            n = Read(connfd, target_user, USERLEN);
            target_user[n] = '\0';
        }else if(strcmp(message_receive, "quit\n") == 0)
        {
            break;
        }
        else
        {
             send_message(username, target_user, message_receive);
        }
       
    }

    delete_user(username);  //将该用户从用户链表中移除
    Close(connfd);
    pthread_exit((void *)1);
}

/*主函数的任务为初始化socket并等待连接，分配线程*/
int main(void)
{
    struct sockaddr_in servaddr;
    socklen_t cliaddr_len;
    struct Th_parameter parameter;
    int listenfd;

    pthread_t ntid;
    int err;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while (1) 
    {
        cliaddr_len = sizeof(parameter.cliaddr);
        parameter.connfd = Accept(listenfd, 
                (struct sockaddr *)&parameter.cliaddr, &cliaddr_len);

        err = pthread_create(&ntid, NULL, th_server, &parameter);
        if (err != 0)
        {
            fprintf(stderr, "can't create thread: %s\n", strerror(err));
            exit(1);
        }

        err = pthread_detach(ntid);
        if (err != 0)
        {
            fprintf(stderr, "can't detach thread: %s\n", strerror(err));
            exit(1);
        }
    }
    return 0;

}
