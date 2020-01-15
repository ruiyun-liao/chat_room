#include "save_record.h"

void save_message(const char *username, const char *target_user, const char *message_save)
{
	char filename[50];
	int  fd_file;
	int write_len = 0;
	if(strcmp(target_user, "all\n") == 0)
	{
		strcpy(filename, "chat_record/all.txt");
	}
	else
	{
		strcpy(filename, "chat_record");
		strcat(filename, "/");
		strcat(filename, username);
		strcpy(&(filename[strlen(filename) - 1]), "_and_");
		strcat(filename, target_user);
		strcpy(&(filename[strlen(filename) - 1]), ".txt");
	}
	
	fd_file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

	write_len = write(fd_file, message_save, strlen(message_save));
	if(write_len != strlen(message_save))
	{
		printf("Write failed!!\n");
		exit(1);
	}

	fd_file = close(fd_file);

	// printf("%d\n", strlen(filename));
	// printf("%s\n", filename);
}

// int main()
// {
// 	save_message("111", "all\n", "const char *message_save\n");
// 	save_message("111", "222", "const char *message_save\n");
// 	return 0;
// } 