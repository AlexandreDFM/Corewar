/*
** EPITECH PROJECT, 2022
** MY_STRTRIM
** File description:
** Function removing trailing whitespaces on a line
*/

#include "../include/corewar.h"

void my_strtrim(char *str)
{
    int i = 0, j = my_strlen(str) - 1;
    while (str[i] == ' ' || str[i] == '\t') i++;
    while (str[j] == ' ' || str[j] == '\t') j--;
    str[++j] = '\0';
}
