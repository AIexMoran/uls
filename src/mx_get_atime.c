#include "uls.h"

static void get_old_time(t_file *file, char *str, int length);

void mx_get_atime(t_file *file, struct stat file_stat) {
    char *str;
    int l_str;

    file->d_access_time = file_stat.st_atime;
    str = ctime(&file_stat.st_atime);
    l_str = mx_strlen(str);
    file->full_access_time = mx_strnew(l_str - 5);
    file->full_access_time = mx_strncpy(file->full_access_time,
    str + 4, l_str - 5);
    if (time(NULL) - file->d_modf_time < 31556926 / 2
        && ((time(NULL) - file->d_modf_time >= 0))) {
        file->access_time = mx_strnew(l_str - 13);
        file->access_time = mx_strncpy(file->access_time,
        str + 4, l_str - 13);
        return;
    }
    get_old_time(file, str, l_str);
}

static void get_old_time(t_file *file, char *str, int length) {
    int k = 0;

    file->access_time = mx_strnew(length - 15);
    for (int i = 0; i < length - 1; i++) {
        if ((i > 3 && i < 11) || i > 19) {
            file->access_time[k] = str[i];
            k++;
        }
        if (i == 11) {
            file->access_time[k] = ' ';
            k++;
        }
    }
}
