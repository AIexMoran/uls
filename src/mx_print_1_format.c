#include "uls.h"

void mx_print_1_format(t_files *files, int flags) {
    if (files->file->den_perms) {
        mx_print_perm_error(files->file->filename);
        return;
    }
    for (t_files *cur = files; cur; cur = cur->next) {
        mx_print_filename(cur->file, flags);
        mx_printstr("\n");
    }
}
