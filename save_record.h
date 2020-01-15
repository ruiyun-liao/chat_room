#ifndef __SAVE_RECORD_H__
#define __SAVE_RECORD_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern void save_message(const char *username, const char *target_user, const char *message_save);

#endif