#include "uls.h"

static void print_error(char *filename);

void mx_print_files(t_files *files, int flags) { //TODO
    for (t_files *cur = files; cur; cur = cur->next) {
        if (cur->file->den_perms) { // checks if file has perms denied
            print_error(cur->file->filename);
            continue;
        }
        printf("file = %s\n", cur->file->filename);
    }
    flags++;
}

static void print_error(char *filename) {
    int index_filename = mx_index_last_char(filename, '/');

    mx_print_error("uls: ");
    mx_print_error(filename + index_filename);
    mx_print_error(": Permission denied\n");
}
