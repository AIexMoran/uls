#ifndef LIBMX_H
#define LIBMX_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <stdbool.h>
#include <malloc/malloc.h>


typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
int mx_list_size(t_list *list);
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);

void mx_del_strarr(char ***strs);
void mx_strdel(char **str);
int mx_count_substr(const char *str, const char *sub);
int mx_strncmp(const char *s1, const char *s2, size_t n);
char *mx_strstr(const char *haystack, const char *needle);
void mx_printspaces(int spaces);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_itoa(int number);
int mx_atoi(const char *str);
bool mx_isspace(char c);
bool mx_isdigit(char c);
void mx_printstr(const char *str);
int mx_numlen(int num);
char *mx_strnew(int s);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_str_reverse(char *s);
char *mx_strdup(const char *str);
int mx_get_char_index(const char *str, char c);
char *mx_strcpy(char *dst, const char *src);
void mx_swap_char(char *s1, char *s2);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_realloc(void *ptr, size_t size);

#endif
