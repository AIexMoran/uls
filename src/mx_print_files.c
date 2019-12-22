#include "uls.h"

static void print_error(char *filename);
static void print_format(t_file *file, int flags);

void mx_print_files(t_files *files, int flags) { //TODO
    t_len_file *len_file = mx_get_length_file(files);

    for (t_files *cur = files; cur; cur = cur->next) {
        if (cur->file->den_perms) { // checks if file has perms denied
            print_error(cur->file->filename);
            continue;
        }
        cur->file->len_file = len_file;
        print_format(cur->file, flags);
    }
    flags++;
}

static void print_format(t_file *file, int flags) {
    if (MX_F_LONG(flags)) {
        mx_print_long_format(file, flags);
    }
}

static void print_error(char *filename) {
    int index_filename = mx_index_last_char(filename, '/');

    mx_print_error("uls: ");
    mx_print_error(filename + index_filename);
    mx_print_error(": Permission denied\n");
}
