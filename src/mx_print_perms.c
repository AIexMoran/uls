#include "uls.h"

void mx_print_perms(t_file *file) {
    mx_printstr(file->perms);
    mx_printstr(file->acl_attr);
}
