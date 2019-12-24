#include "uls.h"

static void print_format(t_files *files, int flags, int size);
static t_files *filter_files(t_files *files, int flags);
static void free_filtered(t_files **filtered);

void mx_print_files(t_files *files, int flags) { //TODO
    int size = 0;
    t_files *filtered = NULL;

    files->len_file = mx_get_length_file(files);
    filtered = filter_files(files, flags);
    size = mx_files_size(filtered);
    if (filtered)
        print_format(filtered, flags, size);
    free_filtered(&filtered);
    free(files->len_file);
}

static void free_filtered(t_files **filtered) {
    t_files *cur = *filtered;
    t_files *tmp = NULL;

    while (cur) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

static t_files *filter_files(t_files *files, int flags) {
    if (MX_F_ISFL(flags)) {
        return mx_al_filter(files);
    }
    else if (MX_F_ISAU(flags)) {
        return mx_A_filter(files);
    }
    else if (!MX_F_ISAL(flags)) {
        return mx_std_filter(files);
    }
    return mx_al_filter(files);
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
