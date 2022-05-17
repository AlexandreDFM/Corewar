/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** write_file
*/

#include "../include/asm.h"

// int little_endian_to_big_endian(int x)
// {
//     int result = 0, i = 0;
//     for (i = 0; i < 4; i++) {
//         result = result << 8;
//         result = result | (x & 0xFF);
//         x = x >> 8;
//     }
//     return result;
// }

// void write_header(t_core *core, char *fighter, int fd)
// {
//     core->magic = little_endian_to_big_endian(core->magic);
//     write(fd, &core->magic, 4);
    
    
//     int size = PROG_NAME_LENGTH + 4;
//     void *data = malloc(size);
//     memset(data, 0, size);
//     my_memcpy(data, core->name, my_strlen(core->name));
    
//     write(fd, data, size);
//     free(data);
    
//     size = COMMENT_LENGTH + 4;
//     data = malloc(size);
//     memset(data, 0, size);
//     my_memcpy(data, core->comment, my_strlen(core->comment));
//     int size2 = little_endian_to_big_endian(my_strlen(core->comment) - my_strlen(core->name));
//     write(fd, &size2, 4);
    
//     write(fd, data, size);
//     free(data);
// }

// void write_commands(t_core *core, int fd)
// {
//     for (t_commands *tmp = core->commands; tmp != NULL; tmp = tmp->next) {
//         printf("%s\n", tmp->op->mnemonique);
//         int size = 1;
//         void *data = malloc(size);
//         memset(data, 0, size);
//         my_memcpy(data, &tmp->op->code, size);
//         write(fd, data, size);
//         // write(fd, tmp->op->mnemonique, my_strlen(tmp->op->mnemonique));
//         // write(fd, &tmp->op->nbr_args, 1);
//         // write(fd, tmp->op->type, my_strlen(tmp->op->type));
//         // write(fd, &tmp->op->nbr_cycles, 4);
//         // write(fd, tmp->op->comment, my_strlen(tmp->op->comment));
//     }
// }

// void write_file(t_core *core, char *fighter)
// {
//     int fd = open(fighter, O_CREAT | O_RDWR, 0777);
//     write_header(core, fighter, fd);
//     write_commands(core, fd);
//     close(fd);
// }
