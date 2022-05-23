/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

void live_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 10;
    champions->infos[LEN_INSTRUCT] = 5;
    champions->infos[NB_LIVE] += 1;
    printf("The player %d(%s)is alive.\n", champions->infos[0],
        champions->name);
    (void)corewar;
}
