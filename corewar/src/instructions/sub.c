/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

void sub_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 10;
    champions->infos[LEN_INSTRUCT] = 5;

    champions->reg[dec_to_hex(corewar->arena->tab[INDEX + 4])[1]] =
        (champions->reg[dec_to_hex(corewar->arena->tab[INDEX + 2])[1]] -
            champions->reg[dec_to_hex(corewar->arena->tab[INDEX + 4])[1]]);
    (void)corewar;
}