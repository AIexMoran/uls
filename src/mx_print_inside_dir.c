#include "uls.h"

void mx_print_inside_dir(t_files *dirs, int flags) { //TODO
    t_files *files = NULL;

    for (t_files *cur = dirs; cur; cur = cur->next) {
        if (dirs->isname)
            printf("%s:\n", cur->file->filename);
        if (dirs->istotal)
            printf("total = TODO\n");
        files = mx_get_all_dir(cur->file);
        mx_print_files(files, flags);
        mx_delete_files(&files);
    }
}
