/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** my_atoi
*/

#include "../include/proto.h"

int my_atoi(char const *str)
{
    int nb = 0, sign = 0;
    if (str[0] == '-') sign = -1;
    if (str[0] == '-' || str[0] == '+') str++;
    for (int i = 0; str[i] != '\0'; ++i)
        nb = nb * 10 + str[i] - '0';
    if (sign == -1)
        nb *= -1;
    return nb;
}
