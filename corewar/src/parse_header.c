/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

void parse_name_champion(t_list_champions *champion)
{
    int name_int = 0;
    for (int i = 4, j = 0, k = 0; i < PROG_NAME_LENGTH + 4; i++, j++) {
        if (champion->file[i] == 0)
            continue;
        name_int = (champion->file[i]) << (BYTE * j) / (my_pow(16, j));
        champion->name[k] = (char)name_int;
        k++;
    }
    printf("name = %s\n", champion->name);
}

void parse_prog_size(t_list_champions *champions)
{
    int size = 0;
    for (int i = PROG_NAME_LENGTH + 8, j= 0; j < 4; i++, j++)
        size += (champions->file[i]) << (BYTE * j) / (my_pow(16, j));
    champions->prog_size = size;
    printf("prog_size = %d\n", champions->prog_size);
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
    printf("comment = %s\n", champions->comment);
}