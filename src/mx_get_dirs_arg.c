#include "uls.h"

static bool isdir_link(int mode, char *filename, int flags);

t_files *mx_get_dirs_arg(char **argv, int size, int flags) {
    t_files *dirs = NULL;
    struct stat file_stat;
    t_file *dir = NULL;

    if (!size) {
        mx_push_file(&dirs, mx_create_file("", "."));
        mx_set_name(dirs, size);
        return dirs;
    }
    for (int i = 0; i < size; i++) {
        if (argv[i]) {
            lstat(argv[i], &file_stat);
            if (isdir_link(file_stat.st_mode, argv[i], flags)) {
                dir = mx_create_file("", argv[i]);
                mx_push_file(&dirs, dir);
            }
        }
    }
    mx_set_name(dirs, size);
    return dirs;
}

static bool isdir_link(int mode, char *filename, int flags) {
    if (mx_valid_link(mode, filename, flags)) {
        return true;
    }
    if ((mode & S_IFMT) == S_IFDIR) {
        return true;
    }
    return false;
}
