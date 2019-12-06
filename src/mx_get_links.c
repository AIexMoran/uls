#include "uls.h"

void mx_get_links(t_file *file, struct stat file_stat) {
    file->links = file_stat.st_nlink;
}
