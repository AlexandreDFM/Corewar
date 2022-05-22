/*
** EPITECH PROJECT, 2022
** MY_H_
** File description:
** Header file for the library
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_atoi(char const *str);
unsigned char *open_file(char *path, int size);
int len_file(char *path);
int switch_endian(int x);
char *my_itoa(int nb);
char *my_revstr(char *str);
void *my_memset(void *dest, int value, int length);
int my_pow(int nb, int power);
char *dec_to_hex(unsigned int nb);
char *hex_to_binary(char *hex);
char *hex_to_binary_from_int(unsigned int nb);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);

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
