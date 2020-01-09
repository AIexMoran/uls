#include "uls.h"

void mx_extend_total(t_files *first, t_files *second) {
    if (first->file->error) {
        first->istotal = false;
        return;
    }
    first->istotal = second->istotal;
}
