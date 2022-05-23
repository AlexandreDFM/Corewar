/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

void add_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 10;
    champions->infos[LEN_INSTRUCT] = 5 + 1;
    champions->reg[champions->infos[INDEX] + 4] =
        (champions->reg[champions->infos[INDEX] + 2] +
        champions->reg[champions->infos[INDEX] + 3]);
    (void)corewar;
    (void)champions;
    printf("add\n");
}
