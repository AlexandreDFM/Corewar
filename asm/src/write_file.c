/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** write_file
*/

#include "../include/asm.h"

int little_endian_to_big_endian(int x, int nb_bytes)
{
    if ((nb_bytes == 4) || (nb_bytes == 2)) {
        int result, i = 0;
        for (i = 0; i < nb_bytes; i++) {
            result = result << 8;
            result = result | (x & 0xFF);
            x = x >> 8;
        }
        return result;
    } else {
        exit(84);
    }
}

void write_header(t_core *core, int fd)
{
    core->header.magic = little_endian_to_big_endian(core->header.magic, 4);
    write(fd, &core->header.magic, 4);

    int size = PROG_NAME_LENGTH + 4;
    void *data = malloc(size); my_memset(data, 0, size);
    my_memcpy(data, core->header.prog_name, my_strlen(core->header.prog_name));

    write(fd, data, size); free(data);

    size = COMMENT_LENGTH + 4; data = malloc(size); my_memset(data, 0, size);
    my_memcpy(data, core->header.comment, my_strlen(core->header.comment));
    core->header.prog_size =
    little_endian_to_big_endian(core->header.prog_size, 4);
    write(fd, &core->header.prog_size, 4);

    write(fd, data, size);
    free(data);
}

void write_commands_loop(t_prog *tmp, int fd)
{
    for (int i = 0; i < tmp->size; i++) {
        if (tmp->print == false) continue;
        if (tmp->stock[i] > 1) {
            tmp->to_write[i] =
            little_endian_to_big_endian(tmp->to_write[i], tmp->stock[i]);
            write(fd, &tmp->to_write[i], tmp->stock[i]);
        } else {
            write(fd, &tmp->to_write[i], tmp->stock[i]);
        }
    }
}

void write_commands(t_core *core, int fd)
{
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        write_commands_loop(tmp, fd);
    }
}

void write_file(t_core *core, char *fighter)
{
    int fd = open(fighter, O_CREAT | O_RDWR, 0777);
    write_header(core, fd);
    write_commands(core, fd);
    close(fd);
}
