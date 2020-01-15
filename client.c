/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "wrap.h"
#include "register.h"

#define ENABLE 1
#define DISABLE 0
#define USERLEN 20
#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;
    char message_send[MAXLINE];
    char message_receive[MAXLINE];
    char username[USERLEN];
    char target_user[USERLEN];
    int sockfd, n;
    fd_set allset;
    int nready;
    int running_flag = DISABLE;

    char chose[10];
    while(1)
    {
        printf("Please chose register or enter\n");
        n = read(0, chose, 10);
        chose[n - 1] = '\0';
        if(strcmp(chose, "quit") == 0)
        {
            return 0;
        }else if(strcmp(chose, "register") == 0)
        {
            user_register(username, USERLEN);
        }else if(strcmp(chose, "enter") == 0)
        {
            if(user_enter(username, USERLEN) == 1)
            {
                break;
            }
        }
    }
    

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Write(sockfd, username, strlen(username));  //发送用户名给服务器

    while(1)
    {
        FD_ZERO(&allset);
        FD_SET(sockfd, &allset);
        FD_SET(STDIN_FILENO, &allset);

        //监视从终端和客户端发来的消息
        nready = select(sockfd+1, &allset, NULL, NULL, NULL);
        if (nready < 0)
        {
            perr_exit("select error");
        }

        if (FD_ISSET(sockfd, &allset))   //如果信息来自网络
        {
            n = Read(sockfd, message_receive, MAXLINE);
            if (n == 0)
            {
                printf("the other side has been closed.\n");
            }
            else
            {
                Write(STDOUT_FILENO, message_receive, n);
            }
        }

        if (FD_ISSET(STDIN_FILENO, &allset))   //如果信息来自标准输入
        {
            fgets(message_send, MAXLINE, stdin);
            if(strcmp(message_send, "quit\n") == 0)
            {
                Write(sockfd, message_send, strlen(message_send));
                break;
            }else if(strcmp(message_send, "mode\n") == 0)  //确定发送消息给谁
            {
                Write(sockfd, message_send, strlen(message_send));
                printf("Please input target_user:\n");
                fgets(target_user, USERLEN, stdin);
                Write(sockfd, target_user, strlen(target_user));
                running_flag = ENABLE;
            }else if(running_flag == DISABLE)
            {
                Write(sockfd, "mode\n", strlen("mode\n"));
                printf("Please input target_user:\n");
                fgets(target_user, USERLEN, stdin);
                Write(sockfd, target_user, strlen(target_user));
                running_flag = ENABLE;
            }
            else  //要发送的消息
            {
                Write(sockfd, message_send, strlen(message_send));
            }
        }

    }

    Close(sockfd);
    return 0;
}
