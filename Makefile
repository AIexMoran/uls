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
	mx_new_file.c \


INCLUDE = -I $(LBMXD) \
	-I $(INCD) \

LBMXS = $(addprefix $(LBMXD)/, $(LMBX))
INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))
	
CFLAGS = -std=c11 -g $(addprefix -W, all extra error pedantic)

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
