#include "uls.h"

void mx_print_files(char **argv, int size, int flags) {
    t_files *files = mx_get_files_arg(argv, size);
    t_files *dirs = mx_get_dirs_arg(argv, size);
    t_files *all_files = mx_get_all_arg(argv, size);
    flags++;
    mx_delete_files(&files);
    mx_delete_files(&dirs);
    mx_delete_files(&all_files);
}
