#include "uls.h"

void mx_get_owner(t_file *file, struct stat file_stat) {
    struct passwd *pw;

    pw = getpwuid(file_stat.st_uid);
    if (pw != NULL) {
        file->owner = mx_strdup(pw->pw_name);
        return;
    }
    file->owner = mx_itoa(file_stat.st_uid);
}
