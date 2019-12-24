#include "uls.h"

bool mx_modf_time_cmp(t_file *f_file, t_file *s_file) {
    long f_modf_time = f_file->d_modf_time;
    long s_modf_time = s_file->d_modf_time;

    return f_modf_time < s_modf_time;
}
