#include "uls.h"

t_files *mx_std_filter(t_files *files) {
    t_files *filtered = NULL;
    t_files *cur = files;

    while (cur) {
        if (cur->file->filename[0] != '.') {
            mx_push_file(&filtered, cur->file);
        }
        cur = cur->next;
    }
    if (filtered) {
        filtered->len_file = files->len_file;
    }
    return filtered;
}
