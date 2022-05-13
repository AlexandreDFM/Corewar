/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-bscorewar-leo.viltard
** File description:
** Created by leo,
*/

#include "../include/proto.h"

int file_bytes(char *path)
{
    int fd = open(path, O_RDONLY);
    off_t cur_pos = lseek(fd, 0, SEEK_CUR);
    off_t size = lseek(fd, 0, SEEK_END);
    cur_pos = lseek(fd, cur_pos, SEEK_SET);
    close(fd);
    return ((int)size);
}

unsigned char *my_read_bytes(char *path, int size_of_read)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0) return NULL;
    unsigned char *buffer = malloc(sizeof(char) * (size_of_read + 1));
    while (read(fd, buffer, size_of_read) > 0);
    close(fd);
    buffer[size_of_read] = '\0';
    return (buffer);
}
