#include "uls.h"

int main() {
    struct stat file_stat;
    char *filename = "Makefile/";

    lstat(filename, &file_stat);
    printf("stat = %lld\n", file_stat.st_size);
}
