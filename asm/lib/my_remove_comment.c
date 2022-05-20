/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** my_remove_comment
*/

#include "../include/proto.h"

void remove_comment(char *str, char garbage)
{
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
        else
            break;
    }
    *dst = '\0';
    if (str[my_strlen(str) - 1] == ' ')
        str[my_strlen(str) - 1] = '\0';
}
