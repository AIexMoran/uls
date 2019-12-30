#include "uls.h"

void mx_get_attr_acl(t_file *file) {
    acl_t acl = NULL;
    ssize_t xattr = 0;
    acl_type_t type = ACL_TYPE_EXTENDED;

    file->acl_attr = mx_strdup("  ");
    xattr = listxattr(file->full_path, NULL, 0, XATTR_NOFOLLOW);
    if (xattr > 0) {
        mx_strdel(&file->acl_attr);
        file->acl_attr = mx_strdup("@ ");
    }
    if (mx_islink(file)) {
        return;
    }
    acl = acl_get_file(file->full_path, type);
    if (acl != NULL && !mx_strcmp(file->acl_attr, "  ")) {
        mx_strdel(&file->acl_attr);
        file->acl_attr = mx_strdup("+ ");
    }
    acl_free(acl);
}
