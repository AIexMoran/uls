#include "uls.h"

bool mx_isflag(char *arg) {
    return *arg == '-' && *(arg + 1);
}
