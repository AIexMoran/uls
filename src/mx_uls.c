#include "uls.h"

int main(int argc, char **argv) {
    argc++;
    argv++;

    t_files *files = mx_new_file(mx_create_file("makefile", "makefile"));
    printf("%s\n", files->file->filename);
    system("leaks -q uls");
}
