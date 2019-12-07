#include "uls.h"

t_files *mx_get_dirs_arg(char **argv, int size) {
    t_files *dirs = NULL;
    struct stat file_stat;
    t_file *dir = NULL;

    for (int i = 0; i < size; i++) {
        if (argv[i]) {
            lstat(argv[i], &file_stat);
            if ((file_stat.st_mode & S_IFMT) == S_IFDIR) {
                dir = mx_create_file("./", argv[i]);
                mx_push_file(&dirs, dir);
            }
        }
    }
    return dirs;
}
