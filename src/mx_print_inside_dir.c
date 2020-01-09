#include "uls.h"

int mx_print_inside_dir(t_files *dirs, int flags) {
    t_files *files = NULL;
    int retval = 0;

    for (t_files *cur = dirs; cur; cur = cur->next) {
        mx_extend_name(cur, dirs);
        mx_print_name(cur);
        files = mx_get_all_dir(cur->file);
        mx_extend_total(files, dirs);
        mx_print_files(files, flags);
        if (files->file->error)
            retval = 1;
        mx_delete_files(&files);
        mx_print_nl(cur->next != NULL);
    }
    return retval;
}
