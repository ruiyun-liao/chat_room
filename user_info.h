#ifndef __USER_INFO_H__
#define __USER_INFO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User    //用以存储用户信息
{
    char name[20];
    int connfd;
    struct User *pre;
    struct User *next;
};

extern struct User *head;

extern int get_connfd(char *name);          //输入用户名，返回对应文件描述符
extern void add_user(char *name, int connfd);      
                                     //向用户链表中添加成员，输入用户名和文件描述符


#endif
