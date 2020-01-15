#include "sqlite.h"

sqlite3 * db = NULL;

static int sn = 0;

char temp_username[USERLEN];
char temp_password[15];

void create_table(char * filename)
{
    char * sql;
    char * zErrMsg = 0;
    int rc;

    rc = sqlite3_open(filename,&db);
    if (rc)
    {
        fprintf(stderr,"can't open database%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
    sql = "CREATE TABLE user_data(name varchar(10), password varchar(15))";
    sqlite3_exec(db, sql, 0, 0, &zErrMsg);
}

void open_database(char * filename)
{
    int rc;

    rc = sqlite3_open(filename,&db);
    if (rc)
    {
        fprintf(stderr,"can't open database%s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }
}

void close_table(void)
{
    sqlite3_close(db);
}

void insert_record(char * table, char * name, char * password)
{
    char * sql;
    char * zErrMsg = NULL;

    sql = sqlite3_mprintf("insert into %s values(%s, %s)",
            table, name, password);
    sqlite3_exec(db ,sql, 0, 0, &zErrMsg);
    sqlite3_free(sql);
}

int sqlite_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;

    for(i = 0; i < argc; i++)
    {
        strcpy(temp_username, azColName[i]); 
        strcpy(temp_password, argv[i]);
    
        // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    // printf("\n");

    return 0;
}

void search_all(char * table)
{
    char * sql;
    char * zErrMsg = 0;

    sn = 0;
    printf("database data::::\n");
    sql = sqlite3_mprintf("select * from %s", table);
    sqlite3_exec(db, sql, &sqlite_callback, 0, &zErrMsg);
    sqlite3_free(sql);
}

void search_by_name(char * table, char * name)
{
    char * sql;
    char * zErrMsg = 0;

    sn = 0;

    sql = sqlite3_mprintf("select * from %s where name = %s", table, name);
    
    sqlite3_exec(db, sql, &sqlite_callback, 0, &zErrMsg);

    sqlite3_free(sql);
}

void delete_by_name(char * table, char * name)
{
    int rc ;
    char * sql;
    char * zErrMsg = 0;
    sql = sqlite3_mprintf("delete from %s where name = %s", table, name);
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    sqlite3_free(sql);
}

void delete_all(char * table)
{
    char * sql;
    char * zErrMsg = 0;

    sql = sqlite3_mprintf("delete from %s", table);
    sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    sqlite3_free(sql);
}

int init_data(char *filename)
{
    // create_table(filename);
    open_database(filename);
    return 0;
}



