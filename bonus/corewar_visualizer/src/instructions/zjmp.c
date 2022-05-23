/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

int jump(unsigned int byte_1, unsigned int byte_2)
{
    int neg = 0;
    if (byte_1 / 16 >= 8 && byte_1 / 16 <= 15) neg = 1;
    int jump = (byte_1 % 16) * my_pow(16, 2) +
        (byte_2 / 16) * 16 + (byte_2 % 16);
    if (neg == 1)
        return (jump - my_pow(16, 3));
    else
        return (jump);
}

void zjmp_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 20;
    champions->infos[LEN_INSTRUCT] = 0;
    champions->infos[INDEX] += jump(
        corewar->arena->tab[champions->infos[INDEX] + 1],
        corewar->arena->tab[champions->infos[INDEX] + 2]);
    (void)corewar;
    (void)champions;
}
