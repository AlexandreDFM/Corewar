/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

t_arena *init_vm(void)
{
    t_arena *arena = malloc(sizeof(t_arena));
    arena->nbr_prog = 1;
    arena->cycle = 0;
    arena->cycle_last_check = 0;
    arena->cycle_to_die = CYCLE_TO_DIE;
    my_memset(arena->tab, '\0', MEM_SIZE - 1);
    return arena;
}

void pos_player(t_corewar *corewar)
{
    t_list_champions *champions = corewar->champions;
    unsigned int add = MEM_SIZE / corewar->arena->nbr_prog;
    unsigned base = 0;
    while (champions) {
        champions->address = base;
        champions->reg[1] = base;
        for (int i = 0; i < champions->prog_size; i++)
            corewar->arena->tab[base + i] = champions->command[i];
        base += add;
        champions = champions->next;
    }
}

void launch_vm(t_corewar *corewar)
{
    pos_player(corewar);

}