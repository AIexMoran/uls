#include "uls.h"

static void print_link(t_file *file, int flags);
static void print_filtered_file(char *filename);

void mx_print_filename(t_file *file, int flags) {
    mx_enable_color(file->perms, flags);
    print_filtered_file(file->filename);
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
        print_filtered_file(link);
    }
}

static void print_filtered_file(char *filename) {
    char *filtered_filename = mx_strdup(filename);

    for (int i = 0; i < mx_strlen(filtered_filename); i++) {
        if (mx_isescape(filtered_filename[i])) {
            filtered_filename[i] = '?';
        }
    }
    if (!isatty(1)) {
        mx_printstr(filename);
    }
    else {
        mx_printstr(filtered_filename);
    }
    mx_strdel(&filtered_filename);
}
