#include "uls.h"

t_files *mx_get_all_dir(t_file *dir) {
    char *full_path = mx_format_dir(dir->full_path);
    t_files *files = NULL;
    DIR *directory = opendir(dir->full_path);
    struct dirent *entry;
    t_file *tmp_file = NULL;

    if (!directory) {
        tmp_file = mx_create_file(full_path, dir->filename);
        tmp_file->den_perms = true;
        mx_push_file(&files, tmp_file);
    }
    else {
        while ((entry = readdir(directory))) {
            tmp_file = mx_create_file(full_path, entry->d_name);
            mx_push_file(&files, tmp_file);
        }
        closedir(directory);
    } 
    mx_strdel(&full_path);
    return files;
}
