#include "uls.h"

void mx_disable_color() {
    mx_printstr(MX_SET_COLOR);
    mx_printstr(MX_CLEAR_COLOR);
}
