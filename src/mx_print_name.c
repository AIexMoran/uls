#include "uls.h"

void mx_print_name(t_files *dir) {
    if (dir->isname) {
        mx_printstr(dir->file->filename);
        mx_printstr(":\n");
    }
}
