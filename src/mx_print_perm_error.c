#include "uls.h"

void mx_print_perm_error(char *filename) {
    int index_filename = mx_index_last_char(filename, '/');

    mx_print_error("uls: ");
    mx_print_error(filename + index_filename);
    mx_print_error(": Permission denied\n");
}
