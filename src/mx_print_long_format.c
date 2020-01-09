#include "uls.h"

static void print(t_file *file, int flags);

void mx_print_long_format(t_files *files, int flags) {
    if (files->file->error) {
        mx_print_perm_error(files->file);
        return;
    }
    for (t_files *cur = files; cur; cur = cur->next) {
        cur->file->len_file = files->len_file;
        print(cur->file, flags);
    }
}

static void print(t_file *file, int flags) {
    mx_print_perms(file);
    mx_print_links(file);
    mx_print_owner(file, flags);
    mx_print_group(file, flags);
    mx_print_size(file);
    mx_print_time(file, flags);
    mx_print_filename(file, flags);
    mx_printstr("\n");
}
