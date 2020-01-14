#include "libmx.h"

int mx_hash(void *data) {
    const unsigned char *bytes = data;
    int hash = 7;

    for (int i = 0; i < mx_strlen(data); i++) {
        hash *= bytes[i] * hash ^ 31;
    }
    return hash;
}
