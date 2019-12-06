#include "uls.h"

void mx_get_inode(t_file *file, struct stat file_stat) {
    file->inode = file_stat.st_ino;
}
