#include "uls.h"

int mx_get_end_flags(char **argv, int argc) {
    int flags = 0;

    for (int i = 1; i < argc; i++) {
        if (mx_isflag(argv[i])) {
            flags++;
        }
    }
    return flags;
}
