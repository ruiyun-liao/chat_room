#include "os_file.h"

osa_file_des_t osa_creat(const char *name, osa_mode_t mode)
{
	return creat(name, mode);
}
osa_file_des_t osa_open(const char *pathname, int flags)
{
	return open(pathname, flags);
}
osa_file_des_t osa_open_and_create(const char *pathname, int flags, osa_mode_t mode)
{
	return open(pathname, flags, mode);
}
int osa_closae(osa_file_des_t filedes)
{
	return close(filedes);
}
osa_ssize_t osa_read(osa_file_des_t filedes, void *buffer, osa_size_t nbytes)
{
	return read(filedes, buffer, nbytes);
}
osa_ssize_t osa_write(osa_file_des_t filedes, void *buffer, osa_size_t nbytes)
{
	return write(filedes, buffer, nbytes);
}
osa_off_t osa_lseek(osa_file_des_t fd, osa_off_t offset, int whence)
{
	return lseek(fd, offset, whence);
}