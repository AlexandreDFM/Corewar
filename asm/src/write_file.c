/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** write_file
*/

#include "../include/asm.h"

int little_endian_to_big_endian(int x)
{
    int result = 0, i = 0;
    for (i = 0; i < 4; i++) {
        result = result << 8;
        result = result | (x & 0xFF);
        x = x >> 8;
    }
    return result;
}

void write_header(t_core *core, char *fighter, int fd)
{
    core->header.magic = little_endian_to_big_endian(core->header.magic);
    write(fd, &core->header.magic, 4);

    int size = PROG_NAME_LENGTH + 4;
    void *data = malloc(size); my_memset(data, 0, size);
    my_memcpy(data, core->header.prog_name, my_strlen(core->header.prog_name));

    write(fd, data, size); free(data);

    size = COMMENT_LENGTH + 4; data = malloc(size); my_memset(data, 0, size);
    my_memcpy(data, core->header.comment, my_strlen(core->header.comment));
    core->header.prog_size =
    little_endian_to_big_endian(core->header.prog_size);
    write(fd, &core->header.prog_size, 4);

    write(fd, data, size);
    free(data);
}

void write_commands(t_core *core, int fd)
{
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; i < tmp->size; i++) {
            write(fd, &tmp->to_write[i], tmp->stock[i]);
        }
    }
}

void write_file(t_core *core, char *fighter)
{
    int fd = open(fighter, O_CREAT | O_RDWR, 0777);
    write_header(core, fighter, fd);
    write_commands(core, fd);
    close(fd);
}
