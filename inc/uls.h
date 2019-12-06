#ifndef ULS_H
#define ULS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/errno.h>
#include "inc/libmx.h"

typedef struct s_file {
    char *filename; //d_name in readdir
    char *relative_path;
    char *full_path;
    size_t size; // stat st_size
    char *owner; // getpwuid(info.st_uid) stat(filename, &info)
    char *modf_time; //stat st_mtime
    char *perms; //stat st_mode
    int links; //stat st_ino
    char *group;  //getgrgid(info.st_uid) stat(filename, &info)
    blksize_t blksize; //-k? flag
    blkcnt_t blocks; //-s flag
    char *acl_attr; //ACL -- TODO
    long d_modf_time;
    char *creation_time; //-U flag //added function //SANYA
    char *access_time; //-u flag //added func //SANYA
    char *status_time; //-c flag //added func //SANYA
    long d_creation_time; //for sorting
    long d_access_time; //for sorting
    long d_status_time; //for sorting
    long inode; //inode(serial) number of file //-i flag
    char *full_modf_time;
    char *full_creation_time;
    char *full_access_time;
    char *full_status_time;
} t_file;

t_file* mx_create_file(char *relative_path, char *filename);
void mx_delete_file(t_file *file);

#endif
