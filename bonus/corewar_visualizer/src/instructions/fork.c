/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/bonus.h"

void push_back_new_champ(t_list_champions **list, t_list_champions *champion,
    int new_address, unsigned char *tab)
{
    t_list_champions *new = malloc(sizeof(t_list_champions));
    t_list_champions *tmp = *list; new->next = NULL;
    for (int i = 0; i < 5; i++)
        new->infos[i] = champion->infos[i];
    new->infos[1] = new_address; new->address = new_address;
    for (int i = 0; i < REG_SIZE; i++)
        new->reg[i] = new->reg[i];
    new->command = champion->command; new->comment = champion->command;
    new->name = champion->name; new->prog_size = champion->prog_size;
    new->file = champion->file;
    for (int i = 0; i < new->prog_size; i++)
        tab[new_address + i] = new->command[i];
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new; new->prev = tmp;
}

void fork_instruction(t_corewar *corewar, t_list_champions *champions)
{
    champions->infos[CYCLE_TMP] = 800;
    champions->infos[LEN_INSTRUCT] = 2;
    unsigned int new_address = hex_to_uint(corewar->arena->tab,
    corewar->arena->tab[champions->infos[INDEX] + 1], 2);
    new_address %= IDX_MOD;
    push_back_new_champ(&corewar->champions, champions,
        new_address, corewar->arena->tab);
}
