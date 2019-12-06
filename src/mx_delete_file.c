#include "uls.h"

void mx_delete_file(t_file *file) {
    free(file->filename);
    file->filename = NULL;
    free(file->relative_path);
    file->relative_path = NULL;
    free(file);
    file = NULL;
}
