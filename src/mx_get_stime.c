#include "uls.h"

static void get_old_time(t_file *file, char *str, int length);

void mx_get_stime(t_file *file, struct stat file_stat) {
    char *str;
    int l_str;

    file->d_status_time = file_stat.st_ctime;
    str = ctime(&file_stat.st_ctime);
    l_str = mx_strlen(str);
    file->full_status_time = mx_strnew(l_str - 5);
    file->full_status_time = mx_strncpy(file->full_status_time,
    str + 4, l_str - 5);
    if (time(NULL) - file->d_modf_time < 31556926 / 2
        && ((time(NULL) - file->d_modf_time >= 0))) {
        file->status_time = mx_strnew(l_str - 13);
        file->status_time = mx_strncpy(file->status_time,
        str + 4, l_str - 13);
        return;
    }
    get_old_time(file, str, l_str);
}

static void get_old_time(t_file *file, char *str, int length) {
    int k = 0;

    file->status_time = mx_strnew(length - 13);
    for (int i = 0; i < length - 1; i++) {
        if ((i > 3 && i < 11) || i > 19) {
            file->status_time[k] = str[i];
            k++;
        }
        if (i == 11) {
            file->status_time[k] = ' ';
            k++;
        }
    }
}
