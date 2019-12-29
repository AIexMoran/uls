#include "uls.h"

t_files *mx_get_all_arg(char **argv, int size) {
    t_files *files = NULL;
    t_file *file = NULL;

    if (!size) {
        mx_push_file(&files, mx_create_file("", "."));
        files->istotal = false;
        return files;
    }
    for (int i = 0; i < size; i++) {
        if (argv[i]) {
            file = mx_create_file("", argv[i]);
            mx_push_file(&files, file);
        }
    }
    if (files)
        files->istotal = false;
    return files;
}
