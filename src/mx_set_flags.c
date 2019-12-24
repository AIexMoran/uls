#include "uls.h"

static void set_bit(int *flags, char *argv);
static void set_output_bit(int *flags, char *argv);

int mx_set_flags(char **argv, int end_flags) {
    int flags = 0;
    bool is_atty = isatty(1);

    flags |= is_atty ? C_FLAG : N1_FLAG;
    for (int i = 1; i <= end_flags; i++) {
        set_output_bit(&flags, argv[i]);
        set_bit(&flags, argv[i]);
    }
    flags &= is_atty ? flags : ~G_FLAG;
    return flags;   
}

static void set_output_bit(int *flags, char *argv) {
    int bit = 0;

    for (int i = 1; i < mx_strlen(argv); i++) {
        bit = mx_get_output_bit(argv[i]);
        if (bit & ~MX_OUTPUT_FLAGS) {
            (*flags) &= MX_OUTPUT_FLAGS;
        }
        (*flags) |= bit;
    }
}

static void set_bit(int *flags, char *argv) {
    for (int i = 1; i < mx_strlen(argv); i++) {
        (*flags) |= mx_get_flag_bit(argv[i]);
    }
}
