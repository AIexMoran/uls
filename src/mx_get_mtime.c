#include "uls.h"

static void get_old_time(t_file *file, char *str, int length);
 
void mx_get_mtime(t_file *file, struct stat file_stat) {
    char *str;
    int length_str;
 
    file->d_modf_time = file_stat.st_mtime;
    str = ctime(&file_stat.st_mtime);
    length_str = mx_strlen(str);
    file->full_modf_time = mx_strdup(str);
    if (time(NULL) - file->d_modf_time < 31556926 / 2
        && ((time(NULL) - file->d_modf_time >= 0))) {
        file->modf_time = mx_strnew(length_str - 13);
        file->modf_time = mx_strncpy(file->modf_time,
        str + 4, length_str - 13);
        return;
    }
    get_old_time(file, str, length_str);
}
 
static void get_old_time(t_file *file, char *str, int length) {
    int k = 0;
 
    file->modf_time = mx_strnew(length - 13);
    for (int i = 0; i < length - 1; i++) {
        if ((i > 3 && i < 11) || i > 19) {
            file->modf_time[k] = str[i];
            k++;
        }
        if (i == 11) {
            file->modf_time[k] = ' ';
            k++;
        }
    }
}
