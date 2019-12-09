#include "uls.h"

static blkcnt_t get_total(t_files *files);
static int get_size_num(blkcnt_t num);
static void set_str(char *str, blkcnt_t result, int size);

void mx_print_total(t_files *files) {
    blkcnt_t result = get_total(files);
    int size = get_size_num(result);
    char *str_result = mx_strnew(size);

    if (!files->istotal) {
        mx_strdel(&str_result);
        return;
    }
    set_str(str_result, result, size);
    mx_printstr("total ");
    if (size == 0)
        mx_printstr("0");
    else
        mx_printstr(str_result);
    mx_printstr("\n");
    mx_strdel(&str_result);
}

static void set_str(char *str, blkcnt_t result, int size) {
    for (int i = 0; i < size; i++) {
        str[i] = result % 10 + '0';
        result /= 10;
    }
    mx_str_reverse(str);
}

static int get_size_num(blkcnt_t num) {
    int size = 0;

    for (blkcnt_t tmp_num = num; tmp_num > 0; tmp_num /= 10) {
        size++;
    }
    return size;
}

static blkcnt_t get_total(t_files *files) {
    blkcnt_t result = 0;

    for (t_files *cur = files; cur; cur = cur->next) {
        result += cur->file->blocks;
    }
    return result;
}
