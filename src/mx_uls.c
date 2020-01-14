#include "uls.h"

static int start(int argc, char **argv);

int main(int argc, char **argv) {
    int retval = start(argc, argv);

    return retval;
}

static int start(int argc, char **argv) {
    int end_flags = mx_get_end_flags(argv, argc);
    int flags = mx_set_flags(argv, end_flags);
    int retval = 0;

    mx_check_flags(argv, argc);
    mx_sort_args(argc, end_flags, argv, flags);
    retval += mx_check_args(argv, end_flags, argc);
    retval += mx_handle_files(argv + end_flags + 1,
    argc - end_flags - 1, flags);
    return retval > 0 ? 1 : 0;
}
