#include "uls.h"

bool mx_is_spec_file(t_file *file) {
    if (file->perms[0] == 'c' || file->perms[0] == 'b') {
        return true;
    }
    return false;
}
