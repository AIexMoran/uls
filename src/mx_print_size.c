#include "uls.h"

static void print_spec(t_file *file);
static void print_std(t_file *file, int flags);

void mx_print_size(t_file *file, int flags) {
    if (mx_is_spec_file(file)) {
        print_spec(file);
    }
    else {
        print_std(file, flags);
    }
    mx_printspaces(1);
}

static void print_spec(t_file *file) {
    int minor_l = mx_numlen(file->minor_num);
    int major_l = mx_numlen(file->major_num);
    char *minor_str = mx_itoa(file->minor_num);
    char *major_str = mx_itoa(file->major_num);

    mx_printspaces(3 - major_l);
    mx_printstr(major_str);
    mx_printstr(", ");
    mx_printspaces(3 - minor_l);
    mx_printstr(minor_str);
    mx_strdel(&minor_str);
    mx_strdel(&major_str);
}

static void print_std(t_file *file, int flags) {
    int size_l = mx_numlen(file->size);
    char *size = mx_itoa(file->size);

    flags++;// TODO
    mx_printspaces(file->len_file->size_l - size_l);  
    mx_printstr(size);
    mx_strdel(&size);
}
