/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

void and_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 6;
    char *pcb = hex_to_binary_from_int(corewar->arena->tab[8]);
    champions->infos[LEN_INSTRUCT] = get_len_instruct_from_pcb(pcb, 4) + 2;
    unsigned int res_op =
        do_op_from_pcb(corewar, pcb, '&', champions->infos[1]);
    champions->reg[pcb[1]] = res_op;
    (void)corewar;
}