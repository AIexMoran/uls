#include "uls.h"

bool mx_std_cmp(t_file *f_file, t_file *s_file) {
    char *f_filename = f_file->filename;
    char *s_filename = s_file->filename;

    return mx_strcmp(f_filename, s_filename) > 0;
}
