#include "uls.h"

static char get_file_type(int mode);
static char get_exec_mode(int mode, int user_type);
static char get_char(int mode, int is_exec, int is_id);

void mx_get_permissions(t_file *file, struct stat file_stat) {
    char *permissions = mx_strnew(10);

    permissions[0] = get_file_type(file_stat.st_mode);
    permissions[1] = (file_stat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (file_stat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = get_exec_mode(file_stat.st_mode, MX_USR);
    permissions[4] = (file_stat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (file_stat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = get_exec_mode(file_stat.st_mode, MX_GRP);
    permissions[7] = (file_stat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (file_stat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = get_exec_mode(file_stat.st_mode, MX_OTH);
    file->perms = permissions;
}

static char get_char(int mode, int is_exec, int is_id) {
    if (mode & is_exec) {
        if (mode & is_id)
            return 's';
        else
            return 'x';
    }
    else {
        if (mode & is_id)
            return 'S';
        else
            return '-';
    }
}

static char get_exec_mode(int mode, int user_type) {
    if (user_type == MX_USR)
        return get_char(mode, S_IXUSR, S_ISUID);
    else if (user_type == MX_GRP)
        return get_char(mode, S_IXGRP, S_ISGID);
    else {
        if (mode & S_IXOTH) {
            if (mode & S_ISTXT)
               return 't';
            else
                return 'x';
        }
        else {
            if (mode & S_ISTXT)
                return 'T';
            else
                return '-';
        }
    }
}

static char get_file_type(int mode) {
    char result = '-';

    if ((mode & S_IFMT) == S_IFCHR)
        return 'c';
    if ((mode & S_IFMT) == S_IFBLK)
        return 'b';
    if ((mode & S_IFMT) == S_IFIFO)
        return 'p';
    if ((mode & S_IFMT) == S_IFSOCK)
        return 's';
    if ((mode & S_IFMT) == S_IFLNK)
        return 'l';
    if ((mode & S_IFMT) == S_IFDIR)
        return 'd';
    return result;
}
