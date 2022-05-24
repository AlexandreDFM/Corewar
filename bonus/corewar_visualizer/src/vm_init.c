/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/bonus.h"

t_arena *init_vm(void)
{
    t_arena *arena = malloc(sizeof(t_arena));
    arena->nbr_prog = 1;
    arena->cycle = 0;
    arena->cycle_last_check = 0;
    arena->cycle_to_die = CYCLE_TO_DIE;
    memset(arena->tab, 0, MEM_SIZE - 1);
    return arena;
}

void pos_player(t_corewar *corewar)
{
    t_list_champions *champions = corewar->champions;
    unsigned int add = MEM_SIZE / corewar->arena->nbr_prog;
    unsigned base = 0; int j = 0;
    while (champions) {
        if (corewar->load_address[j] != 0) {
            base += corewar->load_address[j]; j++;
        }
        champions->address = base;
        champions->infos[1] = champions->address;
        for (int i = 0; i <= champions->prog_size; i++)
            corewar->arena->tab[champions->address + i] = champions->command[i];
        base += add;
        champions = champions->next;
    }
}
