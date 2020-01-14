#include "uls.h"

t_files *mx_get_files_arg(char **argv, int size, int flags) {
    t_files *files = NULL;
    struct stat file_stat;
    t_file *file = NULL;

    for (int i = 0; i < size; i++) {
        if (argv[i]) {
            lstat(argv[i], &file_stat);
            if ((file_stat.st_mode & S_IFMT) != S_IFDIR &&
                !mx_valid_link(file_stat.st_mode, argv[i], flags)) {
                file = mx_create_file("", argv[i]);
                mx_push_file(&files, file);
            }
        }
    }
    if (files)
        files->istotal = false;
    return files;
}
