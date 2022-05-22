/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

void ld_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 5;
    champions->infos[LEN_INSTRUCT] = 4;
    champions->infos[NB_LIVE] += 1;
    (void)corewar;
    (void)champions;
}
