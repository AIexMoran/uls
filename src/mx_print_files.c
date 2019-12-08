#include "uls.h"

static void del_all(t_files *files, t_files *dirs, t_files *all_files);

void mx_print_files(char **argv, int size, int flags) {
    t_files *files = mx_get_files_arg(argv, size);
    t_files *dirs = mx_get_dirs_arg(argv, size);
    t_files *all_files = mx_get_all_arg(argv, size);

    mx_set_total(dirs, flags);
    // printf("dirs_total = %d, dirs_name = %d\n", dirs->istotal, dirs->isname);
    del_all(files, dirs, all_files);
}

static void del_all(t_files *files, t_files *dirs, t_files *all_files) {
    mx_delete_files(&files);
    mx_delete_files(&dirs);
    mx_delete_files(&all_files);
}
