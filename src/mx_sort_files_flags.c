#include "uls.h"

t_files *reverse_files(t_files *files, int flags);

void mx_sort_files_flags(t_files *files, int flags) {
    if (MX_F_ISFL(flags)) {
        return;
    }
    if (MX_F_ISSU(flags)) {
        mx_sort_files(files, mx_size_cmp);
        return;
    }
    mx_sort_files(files, mx_std_cmp);
    files = reverse_files(files, flags);
}

t_files *reverse_files(t_files *files, int flags) {
    t_files *previous = NULL;
    t_files *current = files;
    t_files *next;

    if (MX_F_ISRL(flags)) {
        mx_printstr("OK\n");
        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        files = previous;
    }
    return files;
}
