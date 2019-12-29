#include "uls.h"

void mx_print_name(t_files *dir) {
    if (dir->isname) {
        mx_printstr(dir->file->full_path);
        mx_printstr(":\n");
    }
}
