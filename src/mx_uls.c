#include "uls.h"

int main(int argc, char **argv) {
    argc++;
    argv++;

    t_files *files = mx_new_file(mx_create_file("Makefile", "Makefile"));
    printf("%zu\n", files->file->size);
    system("leaks -q uls");
}
