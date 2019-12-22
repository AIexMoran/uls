#include "uls.h"

bool mx_islink(t_file *file) {
    if (file->perms[0] == 'l') {
        return true;
    }
    return false;
}
