#include "uls.h"

static void get_attributes(t_file *file, struct stat file_stat);

t_file* mx_create_file(char *relative_path, char *filename) {
    t_file *new_file = (t_file*) malloc(sizeof(t_file));
    struct stat file_stat;

    new_file->filename = mx_strdup(filename);
    new_file->relative_path = mx_strdup(relative_path);
    new_file->full_path = mx_get_full_path(filename, relative_path);
    lstat(new_file->full_path, &file_stat);
    get_attributes(new_file, file_stat);
    return new_file;
}

static void get_attributes(t_file *new_file, struct stat file_stat) {
    mx_get_size(new_file, file_stat);
    mx_get_owner(new_file, file_stat);
    mx_get_mtime(new_file, file_stat);
    mx_get_permissions(new_file, file_stat);
    mx_get_links(new_file, file_stat);
    mx_get_group(new_file, file_stat);
    mx_get_block_size(new_file, file_stat);
    mx_get_blocks_count(new_file, file_stat);
    mx_get_ctime(new_file, file_stat);
    mx_get_atime(new_file, file_stat);
}
