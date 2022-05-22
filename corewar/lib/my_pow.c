/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/proto.h"

int my_pow(int nb, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
        result *= nb;
    return (result);
}
