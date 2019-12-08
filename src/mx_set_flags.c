#include "uls.h"

static void set_bit(int *flags, char *argv);

int mx_set_flags(char **argv, int end_flags) {
    int flags = 0;

    for (int i = 1; i <= end_flags; i++) {
        set_bit(&flags, argv[i]);
    } 
    return flags;    
}

static void set_bit(int *flags, char *argv) {
    for (int i = 1; i < mx_strlen(argv); i++) {
        (*flags) |= mx_get_flag_bit(argv[i]);
    }
}
