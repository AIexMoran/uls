#include "uls.h"

static int get_len_filename(t_len_file *len_file, int flags);
static int get_files_line(int len_filename);
static void print(t_file *files_arr[], int flags, int size, int files_line);

void mx_print_xcol_format(t_files *files, int flags, int size) {
    int len_filename = get_len_filename(files->len_file, flags);
    int files_line = get_files_line(len_filename);
    t_file *files_arr[size];

    files->len_file->filename_l = len_filename;
    for (int i = 0; i < size; i++) {
        files_arr[i] = files->file;
        files_arr[i]->len_file = files->len_file;
        if (files->next)
            files->next->len_file = files->len_file;
        files = files->next;
    }
    print(files_arr, flags, size, files_line);
}

static void print(t_file *files_arr[], int flags, int size, int files_line) {
    int len_str = 0;

    for (int i = 0; i < size; i++) {
        mx_print_filename(files_arr[i], flags);
        len_str = mx_strlen(files_arr[i]->filename);
        if ((i + 1) % files_line)
            mx_printspaces(files_arr[0]->len_file->filename_l - len_str);
        if ((i + 1) % files_line == 0 || (i + 1) == size)
            mx_printstr("\n");
    }
}

static int get_files_line(int len_filename) {
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col / len_filename;
}

static int get_len_filename(t_len_file *len_file, int flags) {
    int len = 0;

    if (MX_F_ISGU(flags)) {
        len = len_file->filename_l + 1;
    }
    else {
        len = len_file->filename_l / 8 * 8 + 8;
    }
    return len;
}
