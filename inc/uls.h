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

//flags //edit mx_get_flag_bit!!!
#define MX_FLAGS "-laAgfd" // all flags
// lnosg - all flags that have total
// -f - disable all sort flags
// St - sort flags

/*
    MX_ -> prefix
    F -> flags
    IS -> if
    A or L ... -> name of flag
    U or L -> lower or upper case flag
*/
#define MX_F_ISAL(f) ((f) & (a_FLAG)) // checks is flag: example MX_F_ISAU(flags)
#define MX_F_ISAU(f) ((f) & (A_FLAG))
#define MX_F_ISLL(f) ((f) & (l_FLAG))
#define MX_F_ISGL(f) ((f) & (g_FLAG))
#define MX_F_ISFL(f) ((f) & (f_FLAG))
#define MX_F_ISDL(f) ((f) & (d_FLAG))
#define MX_F_ISSL(f) ((f) & (s_FLAG))
#define MX_F_ISNL(f) ((f) & (n_FLAG))
#define MX_F_ISOL(f) ((f) & (o_FLAG))

typedef enum s_flags {
    a_FLAG = 1 << 0, //0b1
    A_FLAG = 1 << 1, //0b10
    l_FLAG = 1 << 2, //0b100
    g_FLAG = 1 << 3, //0b1000
    f_FLAG = 1 << 4,
    d_FLAG = 1 << 5,
    s_FLAG = 1 << 6,
    n_FLAG = 1 << 7,
    o_FLAG = 1 << 8
} t_flags;
//flags // edit mx_get_flag_bit!!!

typedef struct s_file {
    bool den_perms; //if denied permissions
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
    t_file *file; // file
    bool istotal; // print total
    bool isname; // print name 
    struct s_files *next; // next file
} t_files;

int mx_index_last_char(char *str, char c); // get index char from end
void mx_print_name(t_files *dir); // print name of dir if isname
void mx_extend_name(t_files *first, t_files *second); // extend name from first_dir to second_dir
void mx_extend_total(t_files *first, t_files *second); // extend total from first_dir to second_dir
void mx_print_total(t_files *files); // print total of dir if istotal
t_files *mx_get_all_dir(t_file *dir); // get all files from dir
void mx_print_inside_dir(t_files *dirs, int flags); // print all files inside dir //TODO
void mx_print_files(t_files *files, int flags); // print files
void mx_set_name(t_files *files, int size); // set isname
void mx_set_total(t_files *files, int flags); // set istotal
int mx_get_flag_bit(char bit); // get bit of flag from char ('l')
void mx_handle_files(char **argv, int size, int flags); // main function to handle output of files
void mx_push_file(t_files **files, t_file *file); // push file to list of files
t_files *mx_new_file(t_file *file); // new file
t_file *mx_create_file(char *relative_path, char *filename); // create file //TODO
void mx_delete_file(t_file *file); // delete file // TODO
void mx_sort_files(t_files *files, bool (*cmp)(t_file *, t_file *)); // function to sort files
void mx_sort_args(int argc, int start, char **argv, int flags); // sort args in lexgraphic if not -f flag
bool mx_isflag(char *arg); // check is flag arg
void mx_print_error(char *error); // print in error output
void mx_check_flags(char **argv, int argc);  // check flags
int mx_get_end_flags(char **argv, int argc); // get end index of flag
void mx_check_args(char **argv, int start, int argc); // validation of args
int mx_set_flags(char **argv, int end_flags); // set flags in bits
char *mx_format_dir(char *dir); // format dir to dir '/'
t_files *mx_get_dirs_arg(char **argv, int size); // get only dirs from all args
t_files *mx_get_files_arg(char **argv, int size); // get only files from all args
t_files *mx_get_all_arg(char **argv, int size); // get all from all args
void mx_delete_files(t_files **files); // delete files
void mx_print_nl(bool isprint); // print new line if (something)

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
