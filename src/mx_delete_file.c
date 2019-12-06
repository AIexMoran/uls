#include "uls.h"

void mx_delete_file(t_file *file) {
    mx_strdel(&file->filename);
    mx_strdel(&file->relative_path);
    mx_strdel(&file->full_path);
    mx_strdel(&file->owner);
    mx_strdel(&file->modf_time);
    mx_strdel(&file->perms);
    mx_strdel(&file->group);
    free(file);
    file = NULL;
}
