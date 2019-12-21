#include "uls.h"

static void del_all(t_files *files, t_files *dirs, t_files *all_files);

int mx_handle_files(char **argv, int size, int flags) {
    int retval = 0;
    t_files *files = mx_get_files_arg(argv, size); // get files from argv
    t_files *dirs = mx_get_dirs_arg(argv, size); // get dirs from argv
    t_files *all_files = mx_get_all_arg(argv, size); // get all from argv

    mx_set_total(dirs, flags); // set total to dirs
    //test
    if (MX_F_ISDL(flags)) { // if flag 'd' print all files and dirs without contents
        mx_print_files(all_files, flags); // print all files
    }
    else { // else prints files and contents of dir
        if (files)
            mx_print_files(files, flags);
        mx_print_nl(files && dirs);
        if (dirs)
            retval = mx_print_inside_dir(dirs, flags);
    }
    //test
    del_all(files, dirs, all_files);
    return retval;
}

static void del_all(t_files *files, t_files *dirs, t_files *all_files) {
    mx_delete_files(&files);
    mx_delete_files(&dirs);
    mx_delete_files(&all_files);
}
