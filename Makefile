NAME = uls

SRCD = src
INCD = inc
OBJD = obj
LBMXD = libmx

LMBX = libmx.a
INC = uls.h
SRC = mx_uls.c \
	mx_create_file.c \
	mx_delete_file.c \
	mx_get_full_path.c \
	mx_get_size.c \
	mx_new_file.c \
	mx_get_owner.c \
	mx_get_files_dir.c \
	mx_push_file.c \
	mx_sort_files.c \
	mx_sort_args.c \
	mx_check_flags.c \
	mx_isflag.c \
	mx_print_error.c \
	mx_get_end_flags.c \
	mx_get_mtime.c \
	mx_get_permissions.c \
	mx_get_links.c \
	mx_get_group.c \
	mx_get_block_size.c \
	mx_get_blocks_count.c \
	mx_get_attr_acl.c \
	mx_get_ctime.c \
	mx_get_atime.c \
	mx_get_stime.c \
	mx_get_inode.c \
	mx_check_args.c \
	mx_set_flags.c \
	mx_print_files.c \
	mx_format_dir.c \
	mx_get_dirs_arg.c \
	mx_get_files_arg.c \
	mx_get_all_arg.c \
	mx_delete_files.c \


INCLUDE = -I $(LBMXD) \
	-I $(INCD) \

LBMXS = $(addprefix $(LBMXD)/, $(LMBX))
INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))
	
CFLAGS = -std=c99 -g $(addprefix -W, all extra error pedantic)

all: install clean

install: $(LBMXS) $(NAME)

$(LBMXS):
	@cd $(LBMXD) && make -f Makefile install

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LBMXS) $(OBJS) -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

uninstall: clean
	@cd $(LBMXD) && make -f Makefile uninstall
	@rm -rf $(NAME)	

clean:
	@cd $(LBMXD) && make -f Makefile clean
	@rm -rf $(OBJD)

reinstall: clean all
