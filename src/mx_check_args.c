#include "uls.h"

static void print_error(char *filename);

void mx_check_args(char **argv, int start, int argc) {
    struct stat buff;

    for (int i = start + 1; i < argc; i++) {
        if (lstat(argv[i], &buff) != 0) {
            print_error(argv[i]);
            argv[i] = NULL;
        }
    }
}

static void print_error(char *filename) {
    mx_print_error("uls: ");
    mx_print_error(filename);
    mx_print_error(": ");
    mx_print_error(strerror(errno));
    mx_print_error("\n");
}
