#include "uls.h"

void mx_print_links(t_file *file) {
    int numlen = mx_numlen(file->links);
    char *links = mx_itoa(file->links);

    mx_printspaces(file->len_file->links_l - numlen);
    mx_printstr(links);
    mx_printspaces(1);
    mx_strdel(&links);
}
