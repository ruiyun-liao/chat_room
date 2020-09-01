#ifndef __OS_FILE_H__
#define __OS_FILE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef mode_t   osa_mode_t;
typedef ssize_t  osa_ssize_t;
typedef size_t   osa_size_t;
typedef int      osa_file_des_t;
typedef off_t    osa_off_t;

/*open,flags,required*/
#define  osa_O_RDONLY  O_RDONLY
#define  osa_O_WRONLY  O_WRONLY
#define  osa_O_RDWR    O_RDWR

/*open,flags,choosable*/
#define osa_O_APPEND  O_APPEND
#define osa_O_CREAT   O_CREAT
#define osa_O_EXCL    O_EXCL
#define osa_O_TRUNC   O_TRUNC
#define osa_O_NNBLOCK O_NONBLOCK

/*open/create,mode*/
#define osa_S_IRUSR S_IRUSR
#define osa_S_IWUSR S_IWUSR
#define osa_S_IXUSR S_IXUSR
#define osa_S_IRGRP S_IRGRP
#define osa_S_IWGRP S_IWGRP
#define osa_S_IXGRP S_IXGRP
#define osa_S_IROTH S_IROTH
#define osa_S_IWOTH S_IWOTH
#define osa_S_IXOTH S_IXOTH

/*lseek,whence*/
#define osa_SEEK_SET SEEK_SET
#define osa_SEEK_CUR SEEK_CUR
#define osa_SEEK_END SEEK_END

osa_file_des_t osa_creat(const char *name, osa_mode_t mode);
osa_file_des_t osa_open(const char *pathname, int flags);
osa_file_des_t osa_open_and_create(const char *pathname, int flags, osa_mode_t mode);
int osa_closae(osa_file_des_t filedes);
osa_ssize_t osa_read(osa_file_des_t filedes, void *buffer, osa_size_t nbytes);
osa_ssize_t osa_write(osa_file_des_t filedes, void *buffer, osa_size_t nbytes);
osa_off_t osa_lseek(osa_file_des_t fd, osa_off_t offset, int whence);

#endif