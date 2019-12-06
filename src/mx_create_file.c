#include "uls.h"

t_file* mx_create_file(char *relative_path, char *filename) {
    t_file *new_file = (t_file*)malloc(sizeof(t_file));

    new_file->filename = mx_strdup(filename);
    new_file->relative_path = mx_strdup(relative_path);
    return new_file;
}
