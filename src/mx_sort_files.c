#include "uls.h"

void mx_sort_files(t_files *files, bool (*cmp)(t_file *, t_file *)) {
    t_file *tmp = NULL;

    for (t_files *i = files; i->next; i = i->next) {
        for (t_files *j = i->next; j; j = j->next) {
            if (cmp(i->file, j->file)) {
                tmp = i->file;
                i->file = j->file;
                j->file = tmp;
            }
        }
    }
}
