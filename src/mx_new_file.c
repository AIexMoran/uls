#include "uls.h"

t_files *mx_new_file(t_file *file) {
    t_files *files = malloc(sizeof(t_files));

    files->file = file;
    return files;
}
