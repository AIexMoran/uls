#include "uls.h"

void mx_print_error(char *error) {
    int length = mx_strlen(error);

    write(2, error, length);
}
