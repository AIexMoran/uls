#include "uls.h"

t_files *mx_a_filter(t_files *files) {
    t_files *filtered = NULL;
    t_files *cur = files;
    char *filename = NULL;

    while (cur) {
        filename = cur->file->filename;
        if ((mx_strcmp(filename, ".") &&
            mx_strcmp(filename, "..")) ||
            cur->file->isarg) {
            mx_push_file(&filtered, cur->file);
        }
        cur = cur->next;
    }
    if (filtered) {
        filtered->len_file = files->len_file;
    }
    return filtered;
}
