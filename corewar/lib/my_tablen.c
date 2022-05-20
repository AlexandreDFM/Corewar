/*
** EPITECH PROJECT, 2022
** MY_TABLEN
** File description:
** Function giving size of a char double array
*/

#include "../include/corewar.h"

int my_tablen(char **array)
{
    int i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}
