#include "uls.h"

void mx_set_total(t_files *files, int flags) {
    if (!files) {
        return;
    }
    if (MX_F_ISGL(flags)
        || MX_F_ISLL(flags)
        || MX_F_ISNL(flags)
        || MX_F_ISOL(flags)
        || MX_F_ISSL(flags)) {
        files->istotal = true;
    }
}
