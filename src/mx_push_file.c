#include "uls.h"

void mx_push_file(t_files **files, t_file *file) {
    t_files *cur = *files;

    if (*files == NULL) {
        *files = mx_new_file(file);
        return;
    }
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = mx_new_file(file);
}
