#include "uls.h"

static void del_all(t_files *files, t_files *dirs, t_files *all_files);
static int print_files(t_files *all_files, t_files *files,
t_files *dirs, int flags);

int mx_handle_files(char **argv, int size, int flags) {
    int retval = 0;
    t_files *files = mx_get_files_arg(argv, size);
    t_files *dirs = mx_get_dirs_arg(argv, size);
    t_files *all_files = mx_get_all_arg(argv, size);

    mx_set_total(dirs, flags);
    retval = print_files(all_files, files, dirs, flags);
    del_all(files, dirs, all_files);
    return retval;
}

static int print_files(t_files *all_files, t_files *files,
t_files *dirs, int flags) {
    int retval = 0;

    if (MX_F_ISDL(flags)) {
        flags |= a_FLAG;
        mx_print_files(all_files, flags);
        return retval;
    }
    if (files)
        mx_print_files(files, flags);
    mx_print_nl(files && dirs);
    if (MX_F_ISRU(flags) && dirs) {
        dirs->isfirst = true;
        retval = mx_print_dirs_recursive(dirs, flags);
    }
    else {
        if (dirs)
            retval = mx_print_inside_dir(dirs, flags);
    }
    return retval;
}

static void del_all(t_files *files, t_files *dirs, t_files *all_files) {
    mx_delete_files(&files);
    mx_delete_files(&dirs);
    mx_delete_files(&all_files);
}
