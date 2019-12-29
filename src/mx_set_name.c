#include "uls.h"

void mx_set_name(t_files *files, int size) {
    if (!files) {
        return;
    }
    if (size > 1) {
        files->isname = true;
    }
    else {
        files->isname = false;
    }
}
