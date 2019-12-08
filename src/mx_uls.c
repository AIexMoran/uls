#include "uls.h"

static void test_main(int argc, char **argv);

int main(int argc, char **argv) {
    test_main(argc, argv);
    system("leaks -q uls");
}

static void test_main(int argc, char **argv) {
    int end_flags = mx_get_end_flags(argv, argc);
    int flags = mx_set_flags(argv, end_flags);

    mx_check_flags(argv, argc);
    mx_sort_args(argc, end_flags, argv, flags);
    mx_check_args(argv, end_flags, argc); // ready
    mx_handle_files(argv + end_flags + 1, argc - end_flags - 1, flags);
}
