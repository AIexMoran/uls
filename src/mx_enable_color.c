#include "uls.h"

static void set_for_back_ground(char foreground, char background);
static void set_bits_color(char *perms);
static void set_type_color(char *perms);
static bool is_executeble(char *perms);

void mx_enable_color(char *perms, int flags) {
    if (!MX_F_ISGU(flags)) {
        return;
    }
    set_type_color(perms);
    set_bits_color(perms);
}

static void set_for_back_ground(char foreground, char background) {
    char *color = NULL;
    char *result_color = NULL;

    if (foreground != -1 && background != -1) {
        color = mx_strdup("[30;40m");
        color[2] = foreground;
        color[5] = background;
    }
    else if (foreground != -1) {
        color = mx_strdup("[30m");
        color[2] = foreground;
    }
    else if (background != -1) {
        color = mx_strdup("[40m");
        color[2] = background;
    }
    result_color = mx_strjoin("\x1b", color);
    mx_printstr(result_color);
    mx_strdel(&result_color);
    mx_strdel(&color);
}

static void set_bits_color(char *perms) {
    if (perms[3] == 's' && is_executeble(perms)) {
        set_for_back_ground(MX_BLACK, MX_RED);
    }
    if (perms[6] == 's' && is_executeble(perms)) {
        set_for_back_ground(MX_BLACK, MX_CYAN);
    }
    if (perms[0] == 'd' && perms[8] == 'w' && perms[9] == 't') {
        set_for_back_ground(MX_BLACK, MX_GREEN);
    }
    if (perms[0] == 'd' && perms[8] == 'w' && perms[9] != 't') {
        set_for_back_ground(MX_BLACK, MX_BROWN);
    }
}

static void set_type_color(char *perms) {
    if (perms[0] == 'd')
        set_for_back_ground(MX_BLUE, -1);
    if (perms[0] == 'l')
        set_for_back_ground(MX_MAGENTA, -1);
    if (perms[0] == 's')
        set_for_back_ground(MX_GREEN, -1);
    if (perms[0] == 'p')
        set_for_back_ground(MX_BROWN, -1);
    if (perms[0] == 'b')
        set_for_back_ground(MX_BLUE, MX_CYAN);
    if (perms[0] == 'c')
        set_for_back_ground(MX_BLUE, MX_BROWN);
    if (perms[0] == '-' && is_executeble(perms)) {
        set_for_back_ground(MX_RED, -1);
    }
}

static bool is_executeble(char *perms) {
    return perms[3] == 'x' || perms[6] == 'x' || perms[9] == 'x';
}
