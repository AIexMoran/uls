#include "uls.h"

int mx_index_last_char(char *str, char c) {
    int length = mx_strlen(str);
    int index = 0;

    mx_str_reverse(str);
    index = mx_get_char_index(str, c);
    mx_str_reverse(str);
    return length - index;
}
