#include "uls.h"

void mx_print_owner(t_file *file, int flags) {
    int owner_l = mx_strlen(file->owner);

    if (!MX_F_ISGL(flags)) {
        mx_printstr(file->owner);
        mx_printspaces(2 + file->len_file->owner_l - owner_l);
    }
}
