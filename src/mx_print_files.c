#include "uls.h"

static void print_format(t_files *files, int flags, int size);

void mx_print_files(t_files *files, int flags) { //TODO
    int size = mx_files_size(files);

    files->len_file = mx_get_length_file(files);
    print_format(files, flags, size);
    free(files->len_file);
}

static void print_format(t_files *files, int flags, int size) {
    if (MX_F_ISCU(flags)) {
        mx_print_col_format(files, flags, size);
    }
    else if (MX_F_IS1N(flags)) {
        mx_print_1_format(files, flags);
    }
    else if (MX_F_ISXL(flags)) {
        mx_print_xcol_format(files, flags, size);
    }
    else if (MX_F_LONG(flags)) {
        mx_print_long_format(files, flags);
    }
}
