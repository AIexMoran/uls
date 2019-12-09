#include "uls.h"

void mx_extend_total(t_files *first, t_files *second) {
    first->istotal = second->istotal;
}
