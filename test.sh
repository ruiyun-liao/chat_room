#!/bin/bash
# Author:itxx00@gmail.com

gcc server.c wrap.c user_info.c send_message.c save_record.c -lpthread -o server
gcc client.c wrap.c register.c sqlite.c -o client -lsqlite3
