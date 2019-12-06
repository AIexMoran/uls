#include "uls.h"

#define FLAGS "l"

int main(int argc, char **argv) {
    int end_flags = mx_get_end_flags(argv, argc);
    
    mx_check_flags(argv, FLAGS, argc);
    mx_sort_args(argc, end_flags, argv); // ready

    t_file *file = mx_create_file("", "src/");
    t_files *files = mx_get_files_dir(file);
    for (t_files *cur = files; cur; cur = cur->next) {
        printf("file = %s, filename = %s\n", cur->file->group, cur->file->filename);
    }
    system("leaks -q uls");
}
