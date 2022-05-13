/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** my_memcpy
*/

#include "../include/proto.h"

void my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
}
