#include "uls.h"

static void print_format(t_files *files, int flags, int size);

void mx_print_files(t_files *files, int flags) {
    int size = 0;
    t_files *filtered = NULL;

    if (!files->file->den_perms)
        filtered = mx_filter_files(files, flags);
    else
        mx_push_file(&filtered, files->file);
    size = mx_files_size(filtered);
    if (filtered) {
        filtered->len_file = mx_get_length_file(filtered);
        mx_sort_files_flags(filtered, flags);
        mx_extend_total(filtered, files);
        mx_print_total(filtered);
        print_format(filtered, flags, size);
        free(filtered->len_file);
    }
    mx_free_filtered(&filtered);
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
