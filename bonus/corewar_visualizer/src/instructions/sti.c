/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

unsigned int hex_to_uint(unsigned char *tab, int index_byte,
    int size_instruction)
{
    unsigned int res = 0;

    for (; size_instruction >= 0; size_instruction--, index_byte++)
        res += tab[index_byte] / my_pow(16, size_instruction);

    return (res);
}

unsigned int sti_get_distance(t_corewar *corewar,
    t_list_champions *champions, char *pcb, int size_direct)
{
    char *tmp = malloc(sizeof(char) * strlen(pcb) + 1);
    memset(tmp, '\0', strlen(pcb));
    tmp = strcpy(tmp, pcb); unsigned int param[2] = {0, 0}; tmp += 2;
    for (int i = 0; i < 2; i++, tmp += 2) {
        strncmp(tmp, "01", 2) == 0 ? param[i] = hex_to_uint(
            corewar->arena->tab,
            corewar->arena->tab[champions->infos[INDEX] + 2], 1) :
        strncmp(tmp, "11", 2) == 0 ? param[i] = hex_to_uint(
            corewar->arena->tab,
            corewar->arena->tab[champions->infos[INDEX] + 2], size_direct) :
        strncmp(tmp, "10", 2) == 0 ? param[i] = hex_to_uint(
            corewar->arena->tab,
            corewar->arena->tab[champions->infos[INDEX] + 2], 2) : 0;
    }
    return (param[0] + param[1]);
}

void sti_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 25;
    char *pcb = hex_to_binary_from_int(
        corewar->arena->tab[champions->infos[INDEX] + 1]);
    champions->infos[LEN_INSTRUCT] = get_len_instruct_from_pcb(pcb, 2) + 4;
    unsigned int pos_to_write = sti_get_distance(corewar, champions, pcb, 2) +
        champions->infos[INDEX];
    unsigned int pad_register_content = pad_unsigned_int(
        champions->reg[champions->infos[INDEX + 2]], 4);
    for (int i = 0, j = 3; i < 4; i++, j--) {
        corewar->arena->tab[pos_to_write + i] =
            pad_register_content << BYTE * j;
    }
}
