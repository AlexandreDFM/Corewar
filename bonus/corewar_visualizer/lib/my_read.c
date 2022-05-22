/*
** EPITECH PROJECT, 2022
** read
** File description:
** Function to know information by reading
*/

#include "../include/my.h"

char *open_file(char *mappath, int size_of_read)
{
    char *buffer = malloc(sizeof(char) * (size_of_read + 1));
    int fd = open(mappath, O_RDONLY);
    if (fd < 0) return NULL;
    int total_read = 0, n_read = 0;
    while ((n_read = read(fd, buffer + total_read,
    (size_of_read + 1) - total_read)) > 0) {
        total_read += n_read;
    }
    close(fd);
    buffer[size_of_read] = '\0';
    return (buffer);
}

int count_int_read(char *mappath)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    int read_size = 0;
    ssize_t line_size;
    FILE *fp = fopen(mappath, "r");
    if (!fp) return 84;
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        line_count++;
        read_size += (int) line_size;
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    free(line_buf);
    line_buf = NULL;
    fclose(fp);
    return read_size;
}

int get_rows(char *map)
{
    int nb_rows = 0, counter = 0;
    for (; map[counter] != '\0'; counter++)
        if (map[counter] == '\n') nb_rows += 1;
    return nb_rows;
}

int get_cols(char *map)
{
    int nb_cols = 0;
    for (; map[nb_cols] != '\n' && map[nb_cols] != '\0'; nb_cols++);
    for (int i = 0, j = 0; map[i] != '\0'; i++, j++) {
        if (map[j] == '\n')
            j = 0;
        if (j >= nb_cols)
            nb_cols = j;
    }
    return nb_cols;
}
