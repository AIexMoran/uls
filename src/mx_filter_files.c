#include "uls.h"

t_files *mx_filter_files(t_files *files, int flags) {
    if (MX_F_ISFL(flags)) {
        return mx_al_filter(files);
    }
    else if (MX_F_ISAU(flags)) {
        return mx_A_filter(files);
    }
    else if (!MX_F_ISAL(flags)) {
        return mx_std_filter(files);
    }
    return mx_al_filter(files);
}

void mx_free_filtered(t_files **filtered) {
    t_files *cur = *filtered;
    t_files *tmp = NULL;

    while (cur) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
