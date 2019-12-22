#include "uls.h"

void mx_print_time(t_file *file, int flags) { //TODO
    mx_printstr(file->modf_time);
    mx_printspaces(1);
    flags++;
}
