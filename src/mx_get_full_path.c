#include "uls.h"

char *mx_get_full_path(char *filename, char *relative_path) {
    return mx_strjoin(relative_path, filename);
}
