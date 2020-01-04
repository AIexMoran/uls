#include "uls.h"

void mx_sort_files_flags(t_files *files, int flags) {
    if (MX_F_ISFL(flags)) {
        return;
    }
    if (MX_F_ISSU(flags)) {
        mx_sort_files(files, mx_size_cmp);
    }
    else {
        mx_sort_files(files, mx_std_cmp);
    }
}
