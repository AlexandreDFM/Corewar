/*
** EPITECH PROJECT, 2022
** CONVERSION
** File description:
** Functions converting numbers
*/

#include "../include/asm.h"

int my_nbtohexalow(int nbr)
{
    char *base = "0123456789abcdef";
    int size = 0;
    int mod = nbr;
    while (base[size] != '\0')
        size++;
    if (size <= 1)
        return (nbr);
    mod %= size;
    if (mod < 0)
        mod = -mod;
    if (nbr / size == 0) {
        if (nbr < 0) my_putstr("ERROR NEGATIVE");
        return (nbr);
    }
    my_nbtohexalow(nbr / size);
    return (nbr);
}

int my_pow(int nb, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
        result *= nb;
    return (result);
}

int my_bintohex(char *bin)
{
    int i = 0, nb = 0, len = my_strlen(bin);
    for (i = 0; i < len; i++) {
        if (bin[i] == '1') nb += my_pow(2, len - i - 1);
    }
    return (nb);
}
