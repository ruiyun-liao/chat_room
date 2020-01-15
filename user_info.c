/*user_info.c*/
#include "user_info.h"

struct User *head = NULL;

static struct User *add_node(char *name, int connfd)  //添加节点
{
    struct User *p = (struct User *)malloc(sizeof(struct User));
    strcpy(p->name, name);
    p->connfd = connfd;
    p->pre = NULL;
    p->next = NULL;
    return p;
}

static void insert_head(struct User *p)   //向链表表头插入
{
    if(head == NULL)
    {
        head = p;
    }else
    {
        head->pre = p;
        p->next = head;
        head = p;
    }
}

static struct User *search_node(char *name)  //根据用户名查找链表中的节点
{
    struct User *p = head;
    while(strcmp(name, p->name) != 0)
    {
        p = p->next;
    }
    return p;
}

static void delete_node(struct User *p)   //将节点从链表中移出
{
    if(p == head)    //要删除节点为头节点的情况
    {
        if(p->next == NULL)  //链表中只剩一个节点的情况
        {
            head = NULL;
        }else
        {
            p->next->pre = NULL;
            head = p->next;
            p->next = NULL;
        }
    }else if(p->next == NULL)  //要删除节点为尾节点的情况
    {
        p->pre->next = NULL;
        p->pre = NULL;
    }else        //链表中间节点
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        p->next = NULL;
        p->pre = NULL;
    }
}

static void destory_node(struct User *p)
{
    free(p);
}

int get_connfd(char *name)  //根据用户名查找文件描述符  接口
{
    struct User *p = search_node(name);
    return p->connfd;
}

void add_user(char *name, int connfd)   //添加用户 接口
{
    struct User *p = NULL;
    //struct User *point = NULL;
    p = add_node(name, connfd);
    insert_head(p);

    //point = head;
    //while(point != NULL)
    //{
    //    printf("%s",point->name);
    //    point = point->next;
    // }
}

void delete_user(char *username)
{
    struct User *p = search_node(username);

    delete_node(p);
    destory_node(p);
}



