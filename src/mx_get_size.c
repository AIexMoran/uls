#include "uls.h"

void mx_get_size(t_file *file, struct stat file_stat) {
    file->size = file_stat.st_size;
}
