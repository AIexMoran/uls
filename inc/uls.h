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

//flags
#define FLAGS "-laAgfd" // all flags // edit mx_set_flags!!!

typedef enum s_flags { // edit mx_set_flags!!!
    a_FLAG = 1 << 0,
    A_FLAG = 1 << 1,
    l_FLAG = 1 << 2,
    g_FLAG = 1 << 3,
    f_FLAG = 1 << 4,
    d_FLAG = 1 << 5,
    s_FLAG = 1 << 6,
    n_FLAG = 1 << 7,
    o_FLAG = 1 << 8
} t_flags;
//flags

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

typedef struct s_files { // struct for files
    t_file *file;
    bool istotal;
    bool isname;
    struct s_files *next;
} t_files;

void mx_set_total(t_files *files, int flags);
int mx_get_flag_bit(char bit);
void mx_print_files(char **argv, int size, int flags);
void mx_push_file(t_files **files, t_file *file);
t_files *mx_new_file(t_file *file);
t_file *mx_create_file(char *relative_path, char *filename);
void mx_delete_file(t_file *file);
t_files *mx_get_files_dir(t_file *file);
void mx_sort_files(t_files *files, bool (*cmp)(t_file *, t_file *));
void mx_sort_args(int argc, int start, char **argv, int flags);
bool mx_isflag(char *arg);
void mx_print_error(char *error);
void mx_check_flags(char **argv, int argc);
int mx_get_end_flags(char **argv, int argc);
void mx_check_args(char **argv, int start, int argc);
int mx_set_flags(char **argv, int end_flags);
char *mx_format_dir(char *dir);
t_files *mx_get_dirs_arg(char **argv, int size);
t_files *mx_get_files_arg(char **argv, int size);
t_files *mx_get_all_arg(char **argv, int size);
void mx_delete_files(t_files **files);

char *mx_get_full_path(char *filename, char *relative_path);
void mx_get_size(t_file *file, struct stat file_stat);
void mx_get_owner(t_file *file, struct stat file_stat);
void mx_get_mtime(t_file *file, struct stat file_stat);
void mx_get_permissions(t_file *file, struct stat file_stat);
void mx_get_links(t_file *file, struct stat file_stat);
void mx_get_group(t_file *file, struct stat file_stat);
void mx_get_block_size(t_file *file, struct stat file_stat);
void mx_get_blocks_count(t_file *file, struct stat file_stat);
void mx_get_attr_acl(t_file *file);
void mx_get_ctime(t_file *file, struct stat file_stat);
void mx_get_atime(t_file *file, struct stat file_stat);
void mx_get_stime(t_file *file, struct stat file_stat);
void mx_get_inode(t_file *file, struct stat file_stat);

#endif
