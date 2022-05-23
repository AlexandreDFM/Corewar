/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** Compare a string inf sup or equal sized by n
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL) return 84;
    if (s1[0] == '\0' || s2[0] == '\0') return 84;
    for (int i = 0; s1[i] != 0 && s2[i] != 0 && i < n; i++) {
        if (s1[i] < s2[i]) {
            return (-1);
        } else if (s1[i] > s2[i]) {
            return (1);
        }
    }
    return (0);
}
