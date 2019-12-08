#include "uls.h"

t_files *mx_get_all_dir(t_file *dir) {
    char *full_path = mx_format_dir(dir->full_path);
    t_files *files = NULL;
    DIR *directory = opendir(dir->full_path);
    struct dirent *entry;

    while ((entry = readdir(directory))) {
        mx_push_file(&files,
        mx_create_file(full_path, entry->d_name));
    }
    mx_strdel(&full_path);
    closedir(directory);
    return files;
}
