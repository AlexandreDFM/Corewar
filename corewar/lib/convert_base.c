/*
** EPITECH PROJECT, 2021
** CONVERT_BASE
** File description:
** Function that converts bases
*/

#include "../include/proto.h"

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
    my_memset(hex, '\0', size + 2);
    for (; nb != 0; i++) {
        hex[i] = (nb % 16 + 48);
        nb /= 16;
    }
    my_revstr(hex);
    return hex;
}

char *hex_to_binary(char *hex)
{
    char *base = "0123456789abcdef", j = 0, k = 0;
    char *binary = malloc(sizeof(char) * (my_strlen(hex) * 4 + 1));
    my_memset(binary, 0, (my_strlen(hex) * 4 + 1));
    binary[(my_strlen(hex)) * 4] = '\0';
    bool to_break = false;
    for (int i = 0; hex[i] != '\0'; i++) {
        for (j = 0; base[j] != '\0'; j++)
            (hex[i] == base[j]) ? to_break = true : 0;
        if (to_break == true)
            break;
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
