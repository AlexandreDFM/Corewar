/*
** EPITECH PROJECT, 2022
** OPEN_FILE
** File description:
** Function opening a file in a buffer
*/

#include "../include/bonus.h"

int len_file(char *path)
{
    off_t size, cur_pos;
    int fd = open(path, O_RDONLY);
    cur_pos = lseek(fd, 0, SEEK_CUR);
    size = lseek(fd, 0, SEEK_END);
    cur_pos = lseek(fd, cur_pos, SEEK_SET);
    close(fd);
    return ((int)size);
}

unsigned char *open_file2(char *path, int size)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;
    unsigned char *buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    close(fd);
    buffer[size] = '\0';
    return (buffer);
}
