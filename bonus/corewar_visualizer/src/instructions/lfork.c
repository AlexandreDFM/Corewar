/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

void lfork_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 1000;
    champions->infos[LEN_INSTRUCT] = 2;
    unsigned int new_address = hex_to_uint(corewar->arena->tab,
        corewar->arena->tab[champions->infos[INDEX] + 1], 2);
    push_back_new_champ(&corewar->champions, champions,
        new_address, corewar->arena->tab);
    printf("lfork\n");
}
