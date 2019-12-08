#include "uls.h"

int mx_get_flag_bit(char bit) {
    if (bit == 'l')
        return l_FLAG;
    if (bit == 'a')
        return a_FLAG;
    if (bit == 'A')
        return A_FLAG;
    if (bit == 'g')
        return g_FLAG;
    if (bit == 'f')
        return f_FLAG;
    if (bit == 'd')
        return d_FLAG;
    return 0;
}
