#include "uls.h"

void mx_print_1_format(t_files *files, int flags) {
    if (files->file->error) {
        mx_print_perm_error(files->file);
        return;
    }
    for (t_files *cur = files; cur; cur = cur->next) {
        mx_print_filename(cur->file, flags);
        mx_printstr("\n");
    }
}
