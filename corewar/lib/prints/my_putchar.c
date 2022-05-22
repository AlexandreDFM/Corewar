/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Putchar
*/

#include <unistd.h>
#include "../../include/printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putchar_disp(char *c)
{
    write(1, c, 1);
    return 0;
}
