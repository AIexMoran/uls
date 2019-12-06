#include "uls.h"

t_files *mx_get_files_dir(t_file *file) {
    t_files *files = NULL;
    DIR *directory = opendir(file->full_path);
    struct dirent *entry;

    while ((entry = readdir(directory))) {
        mx_push_file(&files, mx_create_file(file->relative_path, entry->d_name));
    }
    closedir(directory);
    return files;
}
