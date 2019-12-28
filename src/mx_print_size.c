#include "uls.h"

static void print_spec(t_file *file);
static void print_std(t_file *file);
static void print_info(int info);

void mx_print_size(t_file *file) {
    if (mx_is_spec_file(file)) {
        print_spec(file);
    }
    else {
        print_std(file);
    }
    mx_printspaces(1);
}

static void print_spec(t_file *file) {
    int minor_l = mx_numlen(file->minor_num);
    int major_l = mx_numlen(file->major_num);

    mx_printspaces(file->len_file->size_l - 8);
    mx_printspaces(3 - major_l);
    print_info(file->major_num);
    mx_printstr(", ");
    mx_printspaces(3 - minor_l);
    print_info(file->minor_num);
}

static void print_info(int info) {
    char *num = NULL;

    if (info > 255) {
        num = mx_pr_num_to_hex(info);
        mx_printstr(num);
    }
    else {
        num = mx_itoa(info);
        mx_printstr(num);
    }
    mx_strdel(&num);
}

static void print_std(t_file *file) {
    int size_l = mx_numlen(file->size);
    char *size = mx_itoa(file->size);

    mx_printspaces(file->len_file->size_l - size_l);
    mx_printstr(size);
    mx_strdel(&size);
}
