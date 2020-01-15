#include "send_message.h"

void send_message(char *username, char *target_user, char *message_receive)
{
    struct User *p = head;
    char message_send[MAXLINE];
    int user_len = strlen(username);

    strcpy(message_send, username);
    message_send[user_len - 1] = ':';
    strcpy(message_send + user_len, message_receive);

    if(strcmp(target_user, "all\n") == 0)
    {
        while(p != NULL)    //群发消息
        {
            Write(p->connfd, message_send, strlen(message_send));
            p = p->next;
        }
    }else
    {
        while(p != NULL)
        {
            if((strcmp(p->name, username) == 0) || (strcmp(p->name, target_user) == 0))
            {
                Write(p->connfd, message_send, strlen(message_send));
            }
            p = p->next;
        }
    }

    save_message(username, target_user, message_send);
    

}
