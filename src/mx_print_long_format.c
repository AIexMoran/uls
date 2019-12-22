#include "uls.h"

void mx_print_long_format(t_file *file, int flags) {
    mx_print_perms(file);
    mx_print_links(file);
    mx_print_owner(file, flags);
    mx_print_group(file, flags);
    mx_print_size(file, flags);
    mx_print_time(file, flags);
    mx_print_filename(file, flags);
    mx_printstr("\n");
}
