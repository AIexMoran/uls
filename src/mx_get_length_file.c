#include "uls.h"

static t_len_file *get_length_values(t_len_file *l_f, t_files *files);
static int get_l_str(int len, char *str);
static int get_l_dec(int len, size_t size);
static int get_l_size(t_len_file *l_f, t_file *file);

t_len_file *mx_get_length_file(t_files *files) {
    t_len_file *l_f = malloc(sizeof(t_len_file));

    l_f->filename_l = 0;
    l_f->path_l = 0;
    l_f->size_l = 0;
    l_f->owner_l = 0;
    l_f->modf_time_l = 0;
    l_f->perms_l = 0;
    l_f->links_l = 0;
    l_f->group_l = 0;
    l_f->blksize_l = 0;
    l_f->blocks_l = 0;
    return get_length_values(l_f, files);
}

static t_len_file *get_length_values(t_len_file *l_f, t_files *files) {
    t_file *c_f = NULL;

    for (t_files *cur = files; cur; cur = cur->next) {
        c_f = cur->file;
        l_f->filename_l = get_l_str(l_f->filename_l, c_f->filename);
        l_f->path_l = get_l_str(l_f->path_l, c_f->relative_path);
        l_f->size_l = get_l_size(l_f, c_f);
        l_f->owner_l = get_l_str(l_f->owner_l, c_f->owner);
        l_f->modf_time_l = get_l_str(l_f->modf_time_l, c_f->modf_time);
        l_f->perms_l = get_l_str(l_f->perms_l, c_f->perms);
        l_f->links_l = get_l_dec(l_f->links_l, c_f->links);
        l_f->group_l = get_l_str(l_f->group_l, c_f->group);
        l_f->blksize_l = get_l_dec(l_f->group_l, c_f->blksize);
        l_f->blocks_l = get_l_dec(l_f->group_l, c_f->blocks);
    }
    return l_f;
}

static int get_l_size(t_len_file *l_f, t_file *file) {
    if (mx_is_spec_file(file)) {
        return get_l_dec(l_f->size_l, 10000000);
    }
    return get_l_dec(l_f->size_l, file->size);
}

static int get_l_dec(int len, size_t size) {
    int len2 = mx_numlen(size);

    if (len > len2) {
        return len;
    }
    return len2;
}

static int get_l_str(int len, char *str) {
    int str_len = mx_strlen(str);

    if (len > str_len) {
        return len;
    }
    return str_len;
}
