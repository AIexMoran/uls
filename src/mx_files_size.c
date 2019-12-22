#include "uls.h"

int mx_files_size(t_files *files) {
    int size = 0;

    while (files) {
        size++;
        files = files->next;
    }
    return size;
}
