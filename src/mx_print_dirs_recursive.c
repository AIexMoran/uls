#include "uls.h"

static void print_name(t_files *cur, t_files *dirs);
static int print(t_files *filtered, t_files *dirs, int flags);
static void del_all(t_files *files, t_files *filtered);
static bool is_print(t_files *files, t_files *dirs);

int mx_print_dirs_recursive(t_files *dirs, int flags) {
    int retval = 0;
    t_files *files = NULL;
    t_files *filtered = NULL;

    for (t_files *cur = dirs; cur; cur = cur->next) {
        if (is_print(cur, dirs)) {
            continue;
        }
        print_name(cur, dirs);
        files = mx_get_all_dir(cur->file);
        filtered = mx_filter_files(files, flags);
        if (filtered)
            mx_sort_files_flags(filtered, flags);
        retval += print(filtered, dirs, flags);
        mx_printstr("\n");
        retval += mx_print_dirs_recursive(filtered, flags);
        del_all(files, filtered);
    }
    return retval;
}

static bool is_print(t_files *files, t_files *dirs) {
    files->isfirst = dirs->isfirst;
    if ((files->file->perms[0] != 'd' ||
        !mx_strcmp(files->file->filename, "..") ||
        !mx_strcmp(files->file->filename, ".")) &&
        !dirs->isfirst) {
        return true;
    }
    mx_add_slash(files->file);
    return false;
}

static void print_name(t_files *cur, t_files *dirs) {
    int len = mx_strlen(cur->file->full_path);

    cur->file->full_path[len - 1] = '\0';
    mx_extend_name(cur, dirs);
    mx_print_name(cur);
    cur->file->full_path[len - 1] = '/';
    if (!dirs->isname)
        dirs->isname = true;
}

static void del_all(t_files *files, t_files *filtered) {
    mx_delete_files(&files);
    mx_free_filtered(&filtered);
}

static int print(t_files *filtered, t_files *dirs, int flags) {
    int retval = 0;

    if (!filtered) {
        return 0;
    }
    if (filtered->file->error)
        retval = 1;
    filtered->isfirst = false;
    mx_extend_name(filtered, dirs);
    mx_extend_total(filtered, dirs);
    mx_print_files(filtered, flags);
    return retval;
}
