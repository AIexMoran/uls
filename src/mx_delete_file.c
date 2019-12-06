#include "uls.h"

static void delete_string(char *string);

void mx_delete_file(t_file *file) {
    delete_string(file->filename);
    delete_string(file->relative_path);
    delete_string(file->full_path);
    free(file);
    file = NULL;
}

static void delete_string(char *string) {
    free(string);
    string = NULL;
}
