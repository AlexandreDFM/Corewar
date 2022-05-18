/*
** EPITECH PROJECT, 2022
** FREE
** File description:
** Functions to free our work
*/

#include "../include/asm.h"

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
