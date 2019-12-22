#include "uls.h"

void mx_get_minmaj(t_file *new_file, struct stat file_stat) {
    new_file->minor_num = MX_MINOR(file_stat.st_rdev);
    new_file->major_num = MX_MAJOR(file_stat.st_rdev);
}
