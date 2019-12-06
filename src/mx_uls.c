#include "uls.h"

int main(int argc, char **argv) {
    argc++;
    argv++;

    mx_create_file("Makefile", "Makefile");
    system("leaks -q uls");
}
