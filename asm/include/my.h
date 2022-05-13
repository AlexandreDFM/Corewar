/*
** EPITECH PROJECT, 2022
** MY_H_
** File description:
** Header file for the library
*/

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

int len_file(char *path);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

char *open_file(char *path, int size);

void my_putstr(char const *str);
void my_putstr_error(char const *str);

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
