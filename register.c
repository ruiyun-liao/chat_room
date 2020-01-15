#include "register.h"

void user_register(char * username, int max_len)
{
    int n = 0;
    char password[15];
    char temp_password[15];

    printf("Please input username:\n");
    n = read(0, username, max_len);
    username[n] = '\0';      //Converts the received information into a string
    username[n - 1] = '\0';  
    // printf("%s\n",username);

    printf("Please input password:\n");
    n = read(0, password, 15);
    password[n] = '\0';      //Converts the received information into a string

    printf("Please input password again:\n");
    n = read(0, temp_password, 15);
    temp_password[n] = '\0';      //Converts the received information into a string

    if(strcmp(password,temp_password) == 0)
    {
        password[n - 1] = '\0';  
        printf("password is ok !!\n");
        init_data("user_infomation.db");
        insert_record("user_data", username, password);
        printf("This is information of database\n");
        search_all("user_data");
        close_table();
    } else
    {
        printf("Password entry error,User registration failed\n");
        return;
    }
}

int user_enter(char * username, int name_len)
{
    char password[15];
    int n = 0;

    printf("Please input username:\n");
    n = read(0, username, name_len);
    username[n - 1] = '\0';
    username[n] = '\0';

    init_data("user_infomation.db");
    search_by_name("user_data", username);
    close_table();
    username[n - 1] = '\n';

    printf("Please input password:\n");
    n = read(0, password, 15);
    password[n - 1] = '\0';

    if(strcmp(password, temp_password) == 0)
    {
        printf("User enter succeed!!!!\n");
        return 1;
    }
    else
    {
        printf("The password or username is error\n");
        return 0;
    }
}