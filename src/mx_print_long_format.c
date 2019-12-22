#include "uls.h"

static void print(t_file *file, int flags);

void mx_print_long_format(t_files *files, int flags) {
    for (t_files *cur = files; cur; cur = cur->next) {
        if (cur->file->den_perms) { // checks if file has perms denied
            mx_print_perm_error(cur->file->filename);
            continue;
        }
        cur->file->len_file = files->len_file;
        print(cur->file, flags);
    }
}

static void print(t_file *file, int flags) {
    mx_print_perms(file);
    mx_print_links(file);
    mx_print_owner(file, flags);
    mx_print_group(file, flags);
    mx_print_size(file, flags);
    mx_print_time(file, flags);
    mx_print_filename(file, flags);
    mx_printstr("\n");
}
