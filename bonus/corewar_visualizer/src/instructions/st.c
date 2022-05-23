/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

unsigned int st_get_distance(t_corewar *corewar,
    t_list_champions *champions, char *pcb, int size_direct)
{
    char *tmp = malloc(sizeof(char) * my_strlen(pcb) + 1);
    my_memset(tmp, '\0', my_strlen(pcb));
    tmp = my_strcpy(tmp, pcb); unsigned int param = 0;
    my_strncmp(tmp, "11", 2) == 0 ? param = hex_to_uint(
        corewar->arena->tab,
        corewar->arena->tab[champions->infos[INDEX] + 2], size_direct) :
    my_strncmp(tmp, "10", 2) == 0 ? param = hex_to_uint(
        corewar->arena->tab,
        corewar->arena->tab[champions->infos[INDEX] + 2], 2) : 0;
    return (param);
}

int st_param_or_register(char *pcb)
{
    char *tmp = malloc(sizeof(char) * my_strlen(pcb) + 1);
    my_memset(tmp, '\0', my_strlen(pcb));
    tmp = my_strcpy(tmp, pcb); tmp += 2;
    if (my_strncmp(tmp, "01", 2) == 0)
        return 1;
    return 0;
}

void st_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 5;
    char *pcb = hex_to_binary_from_int(
        corewar->arena->tab[champions->infos[INDEX]]);
    champions->infos[LEN_INSTRUCT] = get_len_instruct_from_pcb(pcb, 4) + 2;
    if (st_param_or_register(pcb) == 1)
        champions->reg[corewar->arena->tab[champions->infos[INDEX + 3]] - 1] =
        champions->reg[corewar->arena->tab[champions->infos[INDEX + 2]] - 1];
    else {
        unsigned int distance = st_get_distance(corewar, champions, pcb, 4) %
            IDX_MOD;
        champions->reg[corewar->arena->tab[champions->infos[INDEX + 3]] -
            1] = corewar->arena->tab[champions->infos[INDEX] + distance];
    }
}
