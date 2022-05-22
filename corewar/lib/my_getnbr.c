/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

int my_getnbr(char const *str)
{
    int neg = 1, itr = 0, len = my_strlen(str);
    long nb = 0;

    for (itr; str[itr] == '+' || str[itr] == '-'; itr++) {
        if (str[itr] == '-')
            neg *= -1;
    }
    for (itr; str[itr] != '\0'; itr++) {
        if (str[itr] >= '0' && str[itr] <= '9')
            nb = nb * 10 + str[itr] - '0';
        else
            return (nb * neg);
    }
    if (nb < INT_MIN || nb > INT_MAX)
        return (0);
    return (nb * neg);
}
