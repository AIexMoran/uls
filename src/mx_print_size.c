#include "uls.h"

void mx_print_size(t_file *file, int flags) {
    int size_l = mx_numlen(file->size);
    char *size = mx_itoa(file->size);

    flags++;// TODO
    mx_printspaces(file->len_file->size_l - size_l);
    mx_printstr(size);
    mx_printspaces(1);
    mx_strdel(&size);
}
