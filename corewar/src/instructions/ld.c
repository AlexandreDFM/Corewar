/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

void ld_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->reg[CYCLE_TMP] = 5;
    champions->reg[LEN_INSTRUCT] = 4;
    champions->reg[NB_LIVE] += 1;
}