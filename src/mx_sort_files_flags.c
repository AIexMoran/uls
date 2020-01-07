#include "uls.h"

t_files *reverse_files(t_files *files, int flags);

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
    files = reverse_files(files, flags);
}

t_files *reverse_files(t_files *files, int flags) {
    if (MX_F_ISRL(flags)) {
        t_file *tmp = NULL;
        for (t_files *i = files; i->next; i = i->next) {
            for (t_files *j = i->next; j; j = j->next) {
                tmp = i->file;
                i->file = j->file;
                j->file = tmp;
            }         
        }
    }
    return files;
}
