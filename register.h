#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "sqlite.h"
#include <unistd.h>

extern void user_register(char * username, int max_len);
extern int user_enter(char * username, int name_len);

#endif