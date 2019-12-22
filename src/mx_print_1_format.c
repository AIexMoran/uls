#include "uls.h"

void mx_print_1_format(t_files *files, int flags) {
    for (t_files *cur = files; cur; cur = cur->next) {
        mx_print_filename(cur->file, flags);
        mx_printstr("\n");
    }
}
