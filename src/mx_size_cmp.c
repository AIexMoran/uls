#include "uls.h"

bool mx_size_cmp(t_file *f_file, t_file *s_file) {
    size_t f_size = f_file->size;
    size_t s_size = s_file->size;

    if (f_size == s_size) {
        return mx_std_cmp(f_file, s_file);
    }
    return f_size < s_size;
}
