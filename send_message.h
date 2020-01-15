#ifndef __SEND_MESSAGE_H__  
#define __SEND_MESSAGE_H__


#include "wrap.h"
#include "user_info.h"
#include "save_record.h"

#define MAXLINE 80

void send_message(char *username, char *target_user, char *message_receive);

#endif
