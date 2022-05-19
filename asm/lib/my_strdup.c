/*
** EPITECH PROJECT, 2022
** MY_STRDUP
** File description:
** my_strdup
*/

#include "../include/asm.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (!dest)
        return (NULL);
    my_strncpy(dest, src, my_strlen(src));
    dest[my_strlen(src)] = '\0';
    return (dest);
}
