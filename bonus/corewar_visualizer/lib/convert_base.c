/*
** EPITECH PROJECT, 2021
** CONVERT_BASE
** File description:
** Function that converts bases
*/

#include "../include/bonus.h"

int number_size_base(int nb, int base)
{
    int len = 1;
    while (nb > 1) {
        len++;
        nb /= base;
    }
    return (len);
}

char *dec_to_hex(unsigned int nb)
{
    int size = number_size_base(nb, 16), i = 0;
    char *hex = malloc(sizeof(char) * (size + 2));
    memset(hex, '\0', size + 2);
    for (; nb != 0; i++) {
        hex[i] = (nb % 16 + 48);
        nb /= 16;
    }
    my_revstr(hex);
    return hex;
}

int fct_tempo(char *base, char *hex, int j, int i)
{
    for (j = 0; base[j] != '\0'; j++)
        if (hex[i] == base[j]) break;
    return (j);
}

char *hex_to_binary(char *hex)
{
    char *base = "0123456789abcdef"; int j = 0, k = 0;
    char *binary = malloc(sizeof(char) * (strlen(hex) * 4 + 1));
    memset(binary, 0, (strlen(hex) * 4 + 1));
    binary[(strlen(hex)) * 4] = '\0';
    for (int i = 0; hex[i] != '\0'; i++) {
        j = fct_tempo(base, hex, j, i);
        for (; j != 0; k++) {
            binary[k] = j % 2 + 48;
            j /= 2;
        }
    }
    return binary;
}

char *hex_to_binary_from_int(unsigned int nb)
{
    char *hex = dec_to_hex(nb);
    char *bin = hex_to_binary(hex);
    free(hex);
    return bin;
}
