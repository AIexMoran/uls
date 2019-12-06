#include "uls.h"

void mx_get_blocks_count(t_file *file, struct stat file_stat) {
    file->blocks = file_stat.st_blocks;
}
