#include "uls.h"

void mx_disable_color(int flags) {
    if (!MX_F_ISGU(flags)) {
        return;
    }
    mx_printstr(MX_SET_COLOR);
    mx_printstr(MX_CLEAR_COLOR);
}
