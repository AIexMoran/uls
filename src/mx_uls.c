#include "uls.h"

int main(int argc, char **argv) {
    argc++;
    argv++;

    t_file *file = mx_create_file("Makefile", "Makefile");
    mx_delete_file(file);
    system("leaks -q uls");
}
