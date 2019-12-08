#include "uls.h"

char *mx_format_dir(char *dir) {
    int length = mx_strlen(dir);
    char *new_str = mx_strnew(length + 1);

    mx_strcpy(new_str, dir);
    if (dir[length - 1] != '/') {
        new_str[length] = '/';
    }
    return new_str;
}
