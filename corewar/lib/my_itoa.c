/*
** EPITECH PROJECT, 2026
** merge all
** File description:
** Created by leo,
*/

#include "../include/proto.h"
#include <stdlib.h>

int size_itoa(int nb)
{
    int tmp = nb;
    int size = 1;
    while (tmp > 9) {
        tmp /= 10;
        size++;
    }
    if (nb < 0) size++;
    return size;
}

char *my_itoa(int nb)
{
    if (nb == 0) return "0";
    int i = size_itoa(nb);
    char *str = malloc(sizeof(char) * i + 1);
    str[i] = '\0';
    i--;
    int neg = 0;
    if (nb < 0) {
        neg = 1;
        nb *= -1;
    }
    while (nb > 9) {
        str[i] = ((nb - (nb / 10 * 10)) + '0');
        nb /= 10;
        i--;
    }
    str[i] = nb + '0';
    if (neg == 1) str[0] = '-';
    return str;
}
