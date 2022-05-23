/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/my.h"

int switch_endian(int x)
{
    int result = 0, i = 0;
    for (i = 0; i < 4; i++) {
        result = result << 8;
        result = result | (x & 0xFF);
        x = x >> 8;
    }
    return result;
}
