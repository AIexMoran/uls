#include "uls.h"

int mx_get_flag_bit(char bit) {
    if (bit == 'A')
        return A_FLAG;
    if (bit == 'a')
        return a_FLAG;
    if (bit == 'G')
        return G_FLAG;
    if (bit == 'f')
        return f_FLAG;
    if (bit == 't')
        return t_FLAG;
    if (bit == 'S')
        return S_FLAG;
    return 0;
}

int mx_get_output_bit(char bit) {
    if (bit == 'l')
        return l_FLAG;
    if (bit == 'o')
        return o_FLAG;
    if (bit == 'g')
        return g_FLAG;
    if (bit == '1')
        return N1_FLAG;
    if (bit == 'C')
        return C_FLAG;
    if (bit == 'x')
        return x_FLAG;
    return 0;
}
