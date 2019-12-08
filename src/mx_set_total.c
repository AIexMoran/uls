#include "uls.h"

void mx_set_total(t_files *files, int flags) {
    if (flags & g_FLAG || flags & l_FLAG
       || flags & n_FLAG || flags & o_FLAG
       || flags & s_FLAG) {
        files->istotal = true;
    }
}
