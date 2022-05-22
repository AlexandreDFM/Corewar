/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

void my_putuchar(unsigned char c)
{
    int ret = write(1, &c, 1);
    (void)ret;
}

void aff_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 2;
    champions->infos[LEN_INSTRUCT] = 1 + 1;
    my_putuchar(corewar->arena->tab[champions->infos[INDEX + 1] - 1]);
    (void)corewar;
    (void)champions;
}
