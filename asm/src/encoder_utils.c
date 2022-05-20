/*
** EPITECH PROJECT, 2022
** ENCODER_UTILS
** File description:
** Utils for encoder
*/

#include "../include/asm.h"

void clean_buffer(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
}

int clean_space_before_array(char **array, int *i, int j)
{
    int a = *i;
    if (array[a][0] == ' ') {
        j = 0;
        while (array[a][j + 1] != '\0') {
            array[a][j] = array[a][j + 1];
            j++;
        }
        array[a][j] = '\0';
        j = 0;
        *i = a;
    }
    return (j);
}

int clean_space_after_comma(char **array, int *i, int j)
{
    int a = *i;
    if (j != 0 && array[a][j - 1] == ',' && array[a][j] == ' ') {
        while (array[a][j + 1] != '\0') {
            array[a][j] = array[a][j + 1], j++;
        }
        array[a][j] = '\0';
        j = 0;
        *i = a;
    }
    return (j);
}

void clean_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++)
            j = clean_space_before_array(array, &i, j);
    }
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++)
            j = clean_space_after_comma(array, &i, j);
    }
}
