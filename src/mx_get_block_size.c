#include "uls.h"

void mx_get_block_size(t_file *file, struct stat file_stat) {
    file->blksize = file_stat.st_blksize;
}
