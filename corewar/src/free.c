/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

void free_champions(t_list_champions *champions)
{
    t_list_champions *tmp;
    while (champions) {
        free(champions->file);
        free(champions->name);
        free(champions->comment);
        free(champions->command);
        tmp = champions;
        champions = champions->next;
        free(tmp);
    }
}

void free_corewar(t_corewar *corewar)
{
    free_champions(corewar->champions);
    free(corewar->arena);
    free(corewar);
}
