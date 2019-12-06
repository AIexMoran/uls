#include "uls.h"

int main(int argc, char **argv) {
    argc++;
    argv++;

    t_file *file = mx_create_file("", "src/");
    t_files *files = mx_get_files_dir(file);
    for (t_files *cur = files; cur; cur = cur->next) {
        printf("file = %zu, filename = %s\n", cur->file->size, cur->file->filename);
    }
    system("leaks -q uls");
}
