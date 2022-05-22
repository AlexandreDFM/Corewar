/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

void (*tab[16])(t_corewar *, t_list_champions *) = {live_instruction,
    ld_instruction, st_instruction, add_instruction, sub_instruction,
    and_instruction, or_instruction, xor_instruction, zjmp_instruction,
    ldi_instruction, sti_instruction, fork_instruction, lld_instruction,
    lldi_instruction, lfork_instruction, aff_instruction};

void check_champions(t_corewar *corewar)
{
    t_list_champions *champion = corewar->champions;
    while (champion) {
        if (champion->infos[CYCLE_TMP] != 0)
            champion->infos[CYCLE_TMP]--;
        else if (champion->infos[LEN_INSTRUCT] == 0) {
            tab[corewar->arena->tab[champion->infos[INDEX]] - 1](corewar,
                champion);
        }
        else {
            champion->infos[INDEX] += 1;
            champion->infos[LEN_INSTRUCT]--;
        }
        champion = champion->next;
    }
}

int check_winner(t_corewar *corewar)
{
    t_list_champions *champion = corewar->champions;
    int winner = 0;
    while (champion) {
        if (champion->infos[NB_LIVE] != 0) {
            winner = champion->infos[0];
            break;
        }
        champion = champion->next;
    }
    return (winner);
}

void detect_death(t_corewar *corewar)
{
    t_list_champions *champion = corewar->champions;
    while (champion) {
        if (champion->infos[NB_LIVE] == 0) {
            corewar->nbr_death++;
            corewar->one_death = 1;
        }
        if (corewar->nbr_death == (int)corewar->arena->nbr_prog - 1) {
            corewar->winner = champion->infos[0];
            break;
        }
        if (corewar->winner != 0)
            break;
        champion = champion->next;
    }
}

void set_nb_alive_to_zero(t_corewar *corewar)
{
    t_list_champions *champion = corewar->champions;
    while (champion) {
        champion->infos[NB_LIVE] = 0;
        champion = champion->next;
    }
}

void launch_vm(t_corewar *corewar)
{
    pos_player(corewar);
    for (; corewar->winner == 0; corewar->arena->cycle_last_check++,
        corewar->arena->cycle++) {
        if (corewar->arena->cycle_last_check == corewar->arena->cycle_to_die) {
            corewar->arena->cycle_last_check = 0;
            detect_death(corewar);
            set_nb_alive_to_zero(corewar);
            corewar->one_death == 0 ?
                corewar->arena->cycle_to_die -= CYCLE_DELTA : 0;
        }
        check_champions(corewar);
    }
}
