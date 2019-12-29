#include "uls.h"

int mx_print_dirs_recursive(t_files *dirs, int flags) {
    int retval = 0;

    if (mx_files_size(dirs) == 1 && !dirs->isname) {
        retval = mx_print_inside_dir(dirs, flags);
    }
    return retval;
}
