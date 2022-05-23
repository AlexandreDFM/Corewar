/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** Function that copies a string into another
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    for (a = 0; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[a] = '\0';

    return (dest);
}
