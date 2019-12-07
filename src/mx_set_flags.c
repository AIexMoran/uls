#include "uls.h"

static void set_bit(int *flags, char *argv);
static int get_flag_bit(char bit);

int mx_set_flags(char **argv, int end_flags) {
    int flags = 0;

    for (int i = 1; i <= end_flags; i++) {
        set_bit(&flags, argv[i]);
    } 
    return flags;    
}

static void set_bit(int *flags, char *argv) {
    for (int i = 1; i < mx_strlen(argv); i++) {
        (*flags) |= get_flag_bit(argv[i]);
    }
}

static int get_flag_bit(char bit) {
    switch (bit) {
        case 'l':
            return L_FLAG;
        case 'a':
            return a_FLAG;
        case 'A':
            return A_FLAG;
        case 'g':
            return g_FLAG;
        case 'f':
            return f_FLAG;
        case 'd':
            return d_FLAG;
    }
    return 0;
}
