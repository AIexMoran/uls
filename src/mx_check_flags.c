#include "uls.h"

static void print_error(char flag);
static bool check_arg(char *arg);

void mx_check_flags(char **argv, int argc) {
    int end_flags = mx_get_end_flags(argv, argc);

    for (int i = 1; i <= end_flags; i++) {
        if (check_arg(argv[i])) {
            exit(-1);
        }
    }
}

static bool check_arg(char *arg) {
    bool isvalid = false;

    if (!mx_strcmp(arg, "--")) {
        return false;
    }
    for (int i = 1; i < mx_strlen(arg); i++) {
        isvalid = false;
        for (int j = 1; j < mx_strlen(MX_FLAGS); j++) {
            if (arg[i] == MX_FLAGS[j]) {
                isvalid = true;
                break;
            }
        }
        if (!isvalid) {
            print_error(arg[i]);
            return true;
        }
    }
    return false;
}

static void print_error(char flag) {
    mx_print_error("uls: illegal option -- ");
    write(2, &flag, 1);
    mx_print_error("\nusage: uls [");
    mx_print_error(MX_FLAGS);
    mx_print_error("] [file ...]\n");
}
