/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/bonus.h"

void if_magic(t_list_champions *champions)
{
    int magic = 0;
    for (int i = 1; i < 4; i++)
        magic += switch_endian(champions->file[i] << (BYTE * i));
    if (magic != COREWAR_EXEC_MAGIC) {
        my_putstr("Bad Magic!\n");
        exit(84);
    }
}

void parse_name_champion(t_list_champions *champion)
{
    int name_int = 0;
    for (int i = 4, j = 0, k = 0; i < PROG_NAME_LENGTH + 4; i++, j++) {
        if (champion->file[i] == 0)
            continue;
        name_int = (champion->file[i]);
        champion->name[k] = (char)name_int;
        k++;
    }
}

void parse_prog_size(t_list_champions *champions)
{
    int size = 0;
    for (int i = PROG_NAME_LENGTH + 8, j = 0; j < 4; i++, j++)
        size += (champions->file[i]) << (BYTE * j) / (my_pow(16, j));
    champions->prog_size = size;
}

void parse_comment(t_list_champions *champions)
{
    int i = PROG_NAME_LENGTH + 12;
    for (int j = 0, k = 0; j < COMMENT_LENGTH; i++, j++) {
        if (champions->file[i] == 0)
            continue;
        int byte = champions->file[i];
        int comment_int = byte;
        champions->comment[k] = (char)comment_int;
        k++;
    }
}

void parse_command(t_list_champions *champions)
{
    int i = (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
    champions->command = malloc(sizeof(char) * champions->prog_size + 1);
    memset(champions->command, '\0', champions->prog_size);
    for (int j = 0; j < champions->prog_size; i++, j++)
        champions->command[j] = champions->file[i] >> 0;
}
