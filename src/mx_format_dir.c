#include "uls.h"

char *mx_format_dir(char *dir) {
    int length = mx_strlen(dir);

    if (dir[length - 1] != '/') {
        dir = mx_realloc(dir, mx_strlen(dir) + 1);
        dir[length] = '/';
    }
    return dir;
}
