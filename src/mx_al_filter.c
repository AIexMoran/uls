#include "uls.h"

t_files *mx_al_filter(t_files *files) {
    t_files *filtered = NULL;
    t_files *cur = files;

    while (cur) {
        mx_push_file(&filtered, cur->file);
        cur = cur->next;
    }
    if (filtered) {
        filtered->len_file = files->len_file;
    }
    return filtered;
}
