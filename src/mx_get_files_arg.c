#include "uls.h"

t_files *mx_get_files_arg(char **argv, int size) {
    t_files *files = NULL;
    struct stat file_stat;
    t_file *file = NULL;

    for (int i = 0; i < size; i++) {
        if (argv[i]) {
            lstat(argv[i], &file_stat);
            if ((file_stat.st_mode & S_IFMT) != S_IFDIR) {
                file = mx_create_file("", argv[i]);
                mx_push_file(&files, file);
            }
        }
    }
    return files;
}
