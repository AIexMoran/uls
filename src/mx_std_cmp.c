#include "uls.h"

bool mx_std_cmp(t_file *f_file, t_file *s_file) {
    char *f_filename = f_file->full_path;
    char *s_filename = s_file->full_path;

    return mx_strcmp(f_filename, s_filename) > 0;
}
