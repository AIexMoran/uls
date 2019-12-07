NAME = libmx.a

INC = ./inc/libmx.h

HEADTMP = ./libmx.h

SRC = ./mx_strnew.c \
	./mx_strlen.c \
	./mx_strncpy.c \
	./mx_str_reverse.c \
	./mx_strdup.c \
	./mx_get_char_index.c \
	./mx_swap_char.c \
	./mx_strcpy.c \
	./mx_sort_list.c \
	./mx_list_size.c \
	./mx_create_node.c \
	./mx_push_front.c \
	./mx_push_back.c \
	./mx_pop_front.c \
	./mx_pop_back.c \
	./mx_numlen.c \
	./mx_printstr.c \
	./mx_atoi.c \
	./mx_isspace.c \
	./mx_isdigit.c \
	./mx_itoa.c \
	./mx_strjoin.c \
	./mx_strcat.c \
	./mx_strcmp.c \
	./mx_printspaces.c \
	./mx_strstr.c \
	./mx_strncmp.c \
	./mx_count_substr.c \
	./mx_strdel.c \
	./mx_del_strarr.c \
	./mx_realloc.c \
	./mx_memmove.c \
	./mx_memcpy.c \

SRCS = ./src/mx_strnew.c \
	./src/mx_strlen.c \
	./src/mx_strncpy.c \
	./src/mx_str_reverse.c \
	./src/mx_strdup.c \
	./src/mx_get_char_index.c \
	./src/mx_swap_char.c \
	./src/mx_strcpy.c \
	./src/mx_sort_list.c \
	./src/mx_list_size.c \
	./src/mx_create_node.c \
	./src/mx_push_front.c \
	./src/mx_push_back.c \
	./src/mx_pop_front.c \
	./src/mx_pop_back.c \
	./src/mx_numlen.c \
	./src/mx_printstr.c \
	./src/mx_atoi.c \
	./src/mx_isspace.c \
	./src/mx_isdigit.c \
	./src/mx_itoa.c \
	./src/mx_strjoin.c \
	./src/mx_strcat.c \
	./src/mx_strcmp.c \
	./src/mx_printspaces.c \
	./src/mx_strstr.c \
	./src/mx_strncmp.c \
	./src/mx_count_substr.c \
	./src/mx_strdel.c \
	./src/mx_del_strarr.c \
	./src/mx_realloc.c \
	./src/mx_memmove.c \
	./src/mx_memcpy.c \

OBJ = ./mx_strnew.o \
	./mx_strlen.o \
	./mx_strncpy.o \
	./mx_str_reverse.o \
	./mx_strdup.o \
	./mx_get_char_index.o \
	./mx_swap_char.o \
	./mx_strcpy.o \
	./mx_sort_list.o \
	./mx_list_size.o \
	./mx_create_node.o \
	./mx_push_front.o \
	./mx_push_back.o \
	./mx_pop_front.o \
	./mx_pop_back.o \
	./mx_numlen.o \
	./mx_printstr.o \
	./mx_atoi.o \
	./mx_isspace.o \
	./mx_isdigit.o \
	./mx_itoa.o \
	./mx_strjoin.o \
	./mx_strcat.o \
	./mx_strcmp.o \
	./mx_printspaces.o \
	./mx_strstr.o \
	./mx_strncmp.o \
	./mx_count_substr.o \
	./mx_strdel.o \
	./mx_del_strarr.o \
	./mx_realloc.o \
	./mx_memmove.o \
	./mx_memcpy.o \

OBJO = ./obj/mx_strnew.o \
	./obj/mx_strlen.o \
	./obj/mx_strncpy.o \
	./obj/mx_str_reverse.o \
	./obj/mx_strdup.o \
	./obj/mx_get_char_index.o \
	./obj/mx_swap_char.o \
	./obj/mx_strcpy.o \
	./obj/mx_sort_list.o \
	./obj/mx_list_size.o \
	./obj/mx_create_node.o \
	./obj/mx_push_front.o \
	./obj/mx_push_back.o \
	./obj/mx_pop_front.o \
	./obj/mx_pop_back.o \
	./obj/mx_numlen.o \
	./obj/mx_printstr.o \
	./obj/mx_atoi.o \
	./obj/mx_isspace.o \
	./obj/mx_isdigit.o \
	./obj/mx_itoa.o \
	./obj/mx_strjoin.o \
	./obj/mx_strcat.o \
	./obj/mx_strcmp.o \
	./obj/mx_printspaces.o \
	./obj/mx_strstr.o \
	./obj/mx_strncmp.o \
	./obj/mx_count_substr.o \
	./obj/mx_strdel.o \
	./obj/mx_del_strarr.o \
	./obj/mx_realloc.o \
	./obj/mx_memmove.o \
	./obj/mx_memcpy.o \

CFLGS = -g -std=c11 -Wall -Wextra -Wpedantic -Werror 

all: install uninstall

install:
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@ar -rc $(NAME) $(OBJO)

uninstall:
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf $(OBJ)
	@rm -rf ./obj

clean: uninstall
	@rm -rf $(NAME)

reinstall: clean all