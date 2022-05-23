/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

unsigned int lldi_get_distance(t_corewar *corewar,
    t_list_champions *champions, char *pcb, int size_direct)
{
    char *tmp = malloc(sizeof(char) * strlen(pcb) + 1);
    memset(tmp, '\0', strlen(pcb));
    tmp = strcpy(tmp, pcb);
    unsigned int param[2] = {0, 0};
    tmp += 2;
    for (int i = 0; i < 2; i++, tmp += 2) {
        strncmp(tmp, "11", 2) == 0 ? param[i] = hex_to_uint(
            corewar->arena->tab,
            corewar->arena->tab[champions->infos[INDEX] + 2], size_direct) :
            strncmp(tmp, "10", 2) == 0 ? param[i] = hex_to_uint(
                corewar->arena->tab,
                corewar->arena->tab[champions->infos[INDEX] + 2], 2) : 0;
    }
    return (param[0] + param[1]);
}

void lldi_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 50;
    char *pcb = hex_to_binary_from_int(
        corewar->arena->tab[champions->infos[INDEX]]);
    champions->infos[LEN_INSTRUCT] = get_len_instruct_from_pcb(pcb, 4) + 2;
    unsigned int distance = lldi_get_distance(corewar, champions, pcb, 4);
    pcb += 4;
    champions->reg[pcb[2] - 1] =
        corewar->arena->tab[champions->infos[INDEX] + distance];
    printf("lldi\n");
}
