/*
** EPITECH PROJECT, 2021
** MY_STR_TO_WORD_ARRAY
** File description:
** task04 day08
*/

#include "../include/my.h"

int delim(char c, char const *str)
{
    int i = 0;
    while (str[i]) {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

int word_len(char *str, char *delims, int i)
{
    int len = 0;
    while (str[i] != '\0' && delim(str[i], delims) == 0) {
        i++;
        len++;
    }
    return (len);
}

int count_words(char *str, char *delims)
{
    int count = 2;
    int i = 0;
    while (str[i] != '\0') {
        if (delim(str[i], delims) && delim(str[i + 1], delims) == 0)
            count++;
        i++;
    }
    return (count);
}

char **boucle_array(int i, char *str, char *delims, char **array)
{
    int len = 0, j = 0, k = 0;
    while (str[i] != '\0') {
        if (delim(str[i], delims)) {
            i++;
            continue;
        }
        len = word_len(str, delims, i);
        array[j] = malloc(sizeof(char) * (len + 1));
        for (k = 0; k != len; k++, i++)
            array[j][k] = str[i];
        array[j][k] = '\0';
        j++;
        if (str[i] == '\0') break;
        i++;
    }
    array[j] = NULL;
    return (array);
}

char **my_strtwa(char *str, char *delims)
{
    int i = 0;
    char **array = malloc(sizeof(char *) * count_words(str, delims));
    boucle_array(i, str, delims, array);
    return (array);
}
