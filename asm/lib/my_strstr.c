/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Function that reproduces the behavior of the strstr function.
*/

#include "../include/proto.h"

char *my_strstr(char *str, char *to_find)
{
    int i = 0, j = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == to_find[j])
            j++;
        else
            i -= j, j = 0;
        if (to_find[j] == '\0')
            return (&str[i - j + 1]);
    }
    return (NULL);
}
