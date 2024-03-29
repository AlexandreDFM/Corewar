/*
** EPITECH PROJECT, 2022
** MY_H_
** File description:
** Header file for the library
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

#ifndef MY_H_
    #define MY_H_

int count_int_read(char *mappath);
int len_file(char *path);
int my_atoi(char const *str);
int my_strlen(char const *str);
int my_tablen(char **array);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int count_char(char *string, char c);
int check_char(char c, char *presence);
int pos_char(char *string, char *presence);
int check_string(char *string, char *presence);
int test_delim(char c, char *delim);
int my_bintohex(char *bin);
int my_nbtohexalow(int nbr);

unsigned char *my_read_bytes(char *path, int size_of_read);

char *my_revstr(char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *open_file(char *path, int size);
char *my_strdup_value(char *src, int value);
char *my_strdup_to_char(char *src, char *delim);
char *left_slice(char *strslice, char *new_array, int i, int j);
char *right_slice(char *strslice, char *new_array, int i, int j);
char *my_slice_array(int direction, char *strslice, int nbslice);
char *my_strstr(char *str, char *to_find);
char *my_strdup(char const *src);

char **my_strtwa(char *str, char *delims);

void free_array(char **array);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
void my_free_array(char **array);
void my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *dest, int value, int length);
void my_strtrim(char *str);
void remove_comment(char *str, char garbage);

#endif /* !MY_H_ */

#define UNDERLINE   "\033[04m"
#define BOLD        "\033[01m"
#define NORMAL      "\033[00m"
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
