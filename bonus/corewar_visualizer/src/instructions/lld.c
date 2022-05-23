/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

void lld_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 10;
    char *pcb = hex_to_binary_from_int(
        corewar->arena->tab[champions->infos[INDEX]]);
    champions->infos[LEN_INSTRUCT] = get_len_instruct_from_pcb(pcb, 4) + 2;
    unsigned int distance = ld_get_distance(corewar, champions, pcb, 4);
    champions->reg[corewar->arena->tab[champions->infos[INDEX + 3]] - 1] =
        corewar->arena->tab[champions->infos[INDEX] + distance];
}
