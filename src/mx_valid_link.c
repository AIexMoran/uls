#include "uls.h"

bool mx_valid_link(int mode, char *filename, int flags) {
    bool result = false;

    if (((mode & S_IFMT) == S_IFLNK)
        && !MX_F_LONG(flags)) {
        DIR *dir = opendir(filename);

        if (dir) {
            result = true;
            closedir(dir);
        }
    }
    return result;
}
