#include "uls.h"

void mx_print_files(t_files *files, int flags) { //TODO
    for (t_files *cur = files; cur; cur = cur->next) {
        printf("file = %s\n", cur->file->filename);
    }
    flags++;
    printf("\n");
}
