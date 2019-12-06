#include "uls.h"

void mx_get_group(t_file *file, struct stat file_stat) {
    struct group *grp;

    grp = getgrgid(file_stat.st_gid);

    if (grp != NULL) {
        file->group = mx_strdup(grp->gr_name);
        return;
    }
    file->group = mx_itoa(file_stat.st_gid);
}
