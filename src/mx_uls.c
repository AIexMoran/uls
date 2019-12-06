#include "uls.h"

#define FLAGS "-l"

int main(int argc, char **argv) {
    int end_flags = mx_get_end_flags(argv, argc);
    
    mx_check_flags(argv, FLAGS, argc);
    mx_sort_args(argc, end_flags, argv);
    mx_check_args(argv, end_flags, argc); // ready

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    // t_file *file = mx_create_file("", "src/");
    // t_files *files = mx_get_files_dir(file);
    // for (t_files *cur = files; cur; cur = cur->next) {
    //     printf("file = %lld, filename = %s\n", cur->file->blocks, cur->file->filename);
    // }
    system("leaks -q uls");
}
