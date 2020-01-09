#include "uls.h"

void mx_print_perm_error(t_file *file) {
    int index_filename = mx_index_last_char(file->filename, '/');

    mx_print_error("uls: ");
    mx_print_error(file->filename + index_filename);
    mx_print_error(": ");
    mx_print_error(strerror(file->error));
    mx_print_error("\n");
}
