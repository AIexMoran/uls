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
#include <limits.h>
#include "inc/libmx.h"

//flags //edit mx_get_flag_bit!!!
#define MX_FLAGS "-lgo1CxGAafSdTuUcR" // all flags
#define MX_OUTPUT_FLAGS ~0xF
#define MX_COMBINE_FLAGS ~0x380
#define MX_SIZE_TERM 80
// lnosg - all flags that have total
// f - disable all sort flags
// St - sort flags
// lg1Cox - output flags // lgo - group name
// heT - combine-flags

/*
    MX_ -> prefix
    F -> flags
    IS -> if
    A or L ... -> name of flag
    U or L or N -> lower or upper case flag or number
*/
#define MX_F_LONG(f) (((f) & (l_FLAG)) || ((f) & (g_FLAG)) || ((f) & (o_FLAG)))
#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)

#define MX_F_ISLL(f) ((f) & (l_FLAG)) // output flags
#define MX_F_ISGL(f) ((f) & (g_FLAG))
#define MX_F_ISOL(f) ((f) & (o_FLAG))
#define MX_F_ISCU(f) ((f) & (C_FLAG))
#define MX_F_IS1N(f) ((f) & (N1_FLAG))
#define MX_F_ISXL(f) ((f) & (x_FLAG)) // output flags
#define MX_F_ISHL(f) ((f) & (h_FLAG)) // combine flags
#define MX_F_ISTU(f) ((f) & (T_FLAG)) 
#define MX_F_ISUL(f) ((f) & (u_FLAG))
#define MX_F_ISCL(f) ((f) & (c_FLAG))
#define MX_F_ISUU(f) ((f) & (U_FLAG)) // combine flags
#define MX_F_ISAL(f) ((f) & (a_FLAG))// filter flags
#define MX_F_ISAU(f) ((f) & (A_FLAG))// filter flags
#define MX_F_ISSU(f) ((f) & (S_FLAG)) // sort flags
#define MX_F_ISSL(f) ((f) & (s_FLAG))
#define MX_F_ISFL(f) ((f) & (f_FLAG))
#define MX_F_ISDL(f) ((f) & (d_FLAG))
#define MX_F_ISNL(f) ((f) & (n_FLAG))
#define MX_F_ISGU(f) ((f) & (G_FLAG))
#define MX_F_ISTL(f) ((f) & (t_FLAG))
#define MX_F_ISRU(f) ((f) & (R_FLAG))

#define MX_SET_COLOR "\x1b"
#define MX_CLEAR_COLOR "[0m"
#define MX_BLACK '0'
#define MX_RED '1'
#define MX_GREEN '2'
#define MX_BROWN '3'
#define MX_BLUE '4'
#define MX_MAGENTA '5'
#define MX_CYAN '6'
#define MX_LGRAY '7'

typedef enum s_flags {
    l_FLAG = 1 << 0, // output flags
    N1_FLAG = 1 << 1,
    x_FLAG = 1 << 2,
    C_FLAG = 1 << 3,
    o_FLAG = 1 << 4,
    g_FLAG = 1 << 5, //output flags
    T_FLAG = 1 << 6, //combine flags
    u_FLAG = 1 << 7,
    U_FLAG = 1 << 8, 
    c_FLAG = 1 << 9, //combine flags
    t_FLAG = 1 << 10, //sort flags
    S_FLAG = 1 << 11, //sort flags
    f_FLAG = 1 << 12,
    d_FLAG = 1 << 13,
    n_FLAG = 1 << 14,
    G_FLAG = 1 << 15,
    s_FLAG = 1 << 16,
    h_FLAG = 1 << 17,
    a_FLAG = 1 << 18,
    A_FLAG = 1 << 19,
    R_FLAG = 1 << 20
} t_flags;

//flags // edit mx_get_flag_bit!!!

typedef struct s_len_file {
    int filename_l;
    int path_l;
    int size_l;
    int owner_l; 
    int modf_time_l; 
    int perms_l; 
    int links_l; 
    int group_l;  
    int blksize_l;
    int blocks_l;
    int acl_attr_l;
} t_len_file;

typedef struct s_file {
    t_len_file *len_file;
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
    char *creation_time; //-U flag //added function //SANYA
    char *access_time; //-u flag //added func //SANYA
    char *status_time; //-c flag //added func //SANYA
    long d_modf_time;
    long d_creation_time; //for sorting
    long d_access_time; //for sorting
    long d_status_time; //for sorting
    long inode; //inode(serial) number of file //-i flag
    char *full_modf_time;
    char *full_creation_time;
    char *full_access_time;
    char *full_status_time;
    int major_num;
    int minor_num;
} t_file;



typedef struct s_files { // struct for files
    t_file *file; // file
    t_len_file *len_file;
    bool isfirst;
    bool istotal; // print total
    bool isname; // print name 
    struct s_files *next; // next file
} t_files;

void mx_print_filename(t_file *file, int flags);
void mx_print_time(t_file *file, int flags); //TODO combintaion
void mx_print_size(t_file *file); //TODO combination
void mx_print_group(t_file *file, int flags);
void mx_print_owner(t_file *file, int flags);
void mx_print_links(t_file *file);
void mx_print_perms(t_file *file);
t_len_file *mx_get_length_file(t_files *_files);
void mx_print_long_format(t_files *files, int flags);
int mx_index_last_char(char *str, char c); // get index char from end
void mx_print_name(t_files *dir); // print name of dir if isname
void mx_extend_name(t_files *first, t_files *second); // extend name from first_dir to second_dir
void mx_extend_total(t_files *first, t_files *second); // extend total from first_dir to second_dir
void mx_print_total(t_files *files); // print total of dir if istotal
t_files *mx_get_all_dir(t_file *dir); // get all files from dir
int mx_print_inside_dir(t_files *dirs, int flags); // print all files inside dir //TODO
void mx_print_files(t_files *files, int flags); // print files
void mx_set_name(t_files *files, int size); // set isname
void mx_set_total(t_files *files, int flags); // set istotal
int mx_get_flag_bit(char bit); // get bit of flag from char ('l')
int mx_handle_files(char **argv, int size, int flags); // main function to handle output of files
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
int mx_check_args(char **argv, int start, int argc); // validation of args
int mx_set_flags(char **argv, int end_flags); // set flags in bits
char *mx_format_dir(char *dir); // format dir to dir '/'
t_files *mx_get_dirs_arg(char **argv, int size); // get only dirs from all args
t_files *mx_get_files_arg(char **argv, int size); // get only files from all args
t_files *mx_get_all_arg(char **argv, int size); // get all from all args
void mx_delete_files(t_files **files); // delete files
void mx_print_nl(bool isprint); // print new line if (something)
int mx_get_output_bit(char bit);
int mx_get_combine_bit(char bit);
void mx_print_1_format(t_files *files, int flags);
void mx_print_col_format(t_files *files, int flags, int size);
void mx_print_xcol_format(t_files *files, int flags, int size);
int mx_files_size(t_files *files);
void mx_print_perm_error(char *filename);
bool mx_is_spec_file(t_file *file);
void mx_get_minmaj(t_file *new_file, struct stat file_stat);
bool mx_islink(t_file *file);
void mx_enable_color(char *perms, int flags);
void mx_disable_color(int flags);
t_files *mx_std_filter(t_files *files);
t_files *mx_A_filter(t_files *files);
t_files *mx_al_filter(t_files *files);
bool mx_std_cmp(t_file *f_file, t_file *s_file);
bool mx_modf_time_cmp(t_file *f_file, t_file *s_file);
bool mx_size_cmp(t_file *f_file, t_file *s_file);
int mx_print_dirs_recursive(t_files *dirs, int flags);
void mx_sort_files_flags(t_files *dirs, int flags);
t_files *mx_filter_files(t_files *files, int flags);
void mx_free_filtered(t_files **filtered);

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
