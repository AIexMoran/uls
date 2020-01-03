#include "uls.h"

static void delete_time(t_file *file);

void mx_delete_file(t_file *file) {
    mx_strdel(&file->filename);
    mx_strdel(&file->relative_path);
    mx_strdel(&file->full_path);
    mx_strdel(&file->owner);
    mx_strdel(&file->perms);
    mx_strdel(&file->group);
    mx_strdel(&file->acl_attr);
    delete_time(file);
    free(file);
    file = NULL;
}

static void delete_time(t_file *file) {
    mx_strdel(&file->creation_time);
    mx_strdel(&file->access_time);
    mx_strdel(&file->status_time); //ERROR
    mx_strdel(&file->modf_time);
    mx_strdel(&file->full_modf_time);
    mx_strdel(&file->full_creation_time);
    mx_strdel(&file->full_access_time);
    mx_strdel(&file->full_status_time); //ERROR
}
