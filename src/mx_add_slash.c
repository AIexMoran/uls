#include "uls.h"

void mx_add_slash(t_file *cur) {
    int len = mx_strlen(cur->full_path);
    char *new_full_path = mx_strnew(len + 1);

    mx_strcpy(new_full_path, cur->full_path);
    mx_strdel(&cur->full_path);
    new_full_path[len] = '/';
    cur->full_path = new_full_path;
}
