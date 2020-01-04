#include "uls.h"

static void print_link(t_file *file, int flags);

void mx_print_filename(t_file *file, int flags) { //TODO 
    mx_enable_color(file->perms, flags);
    mx_printstr(file->filename);
    if (mx_islink(file)) {
        print_link(file, flags);
    }
    mx_disable_color(flags);
}

static void print_link(t_file *file, int flags) { 
    char link[1024];
    int bytes_read = 0;

    if (!MX_F_LONG(flags)) {
        return;
    }
    if (mx_islink(file)) {
        bytes_read = readlink(file->full_path, link, sizeof(link) - 1);
        link[bytes_read] = '\0';
        mx_printstr(" -> ");
        mx_printstr(link);
    }
}
