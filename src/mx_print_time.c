#include "uls.h"

static char *get_full_time(t_file *file, int flags);
static char *get_time(t_file *file, int flags);

void mx_print_time(t_file *file, int flags) {
    char *format_str = NULL;

    if (MX_F_ISTU(flags)) {
        format_str = get_full_time(file, flags);
    }
    else {
        format_str = get_time(file, flags);
    }
    mx_printstr(format_str);
    mx_printspaces(1);
}

static char *get_time(t_file *file, int flags) {
    if (MX_F_ISUL(flags)) {
        return file->access_time;
    }
    else if (MX_F_ISCL(flags)) {
        return file->status_time;
    }
    else if (MX_F_ISUU(flags)) {
        return file->creation_time;
    }
    else {
        return file->modf_time;
    }
}

static char *get_full_time(t_file *file, int flags) {
    if (MX_F_ISUL(flags)) {
        return file->full_access_time;
    }
    else if (MX_F_ISCL(flags)) {
        return file->full_status_time;
    }
    else if (MX_F_ISUU(flags)) {
        return file->full_creation_time;
    }
    else {
        return file->full_modf_time;
    }
}
