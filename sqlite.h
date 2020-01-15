#ifndef __SQLITE_H__
#define __SQLITE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define USERLEN 20

extern char temp_username[USERLEN];
extern char temp_password[15];

extern void create_table(char * filename);
extern void open_database(char * filename);
extern void close_table(void);
extern void insert_record(char * table, char * name, char * password);
// extern int sqlite_callback(void *NotUsed, int argc, char **argv, char **azColName);
extern void search_all(char * table);
extern void search_by_name(char * table, char * name);
extern void delete_by_name(char * table, char * name);
extern void delete_all(char * table);
extern int init_data(char *filename);

#endif