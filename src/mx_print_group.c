#include "uls.h"

void mx_print_group(t_file *file, int flags) {
    int group_l = mx_strlen(file->group);

    if (!MX_F_ISOL(flags)) {
        mx_printstr(file->group);
        mx_printspaces(2 + file->len_file->group_l - group_l);
    }
}
