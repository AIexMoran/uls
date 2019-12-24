#include "uls.h"

void mx_delete_files(t_files **files) {
    t_files *cur = *files;
    t_files *tmp = NULL;

    while (cur) {
        mx_delete_file(cur->file);
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
