/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for corewar
*/

#include "../include/corewar.h"

void usage(void)
{
    my_putstr(RED BOLD UNDERLINE "USAGE\n" RESET);
    my_putstr("\t./corewar [-dump nbr_cycle] [[-n prog_number]"\
    " [-a load_adress] prog_name] ...\n\n");
    my_putstr(BLUE BOLD UNDERLINE "DESCRIPTION\n" RESET);
    my_putstr(NBR_CYCLE);
    my_putstr(PROG_NUMBER);
    my_putstr(LOAD_ADRESS);
    my_putstr("\t-h --help\t\tdisplay this help.\n");
    return;
}

void error(int ac, char **av)
{
    if (ac == 1) {
        usage();
        exit(84);
    }
}

void corewar_loop(t_corewar *corewar)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (corewar->nbr_cycle > 0) {
        if (corewar->nbr_cycle % corewar->cycle_to_die == 0) {
            corewar->cycle_to_die -= CYCLE_DELTA;
            corewar->check = 1;
        }
        if (corewar->check == 1) {
            corewar->check = 0;
            corewar->nbr_live = 0;
        }
        for (i = 0; i < corewar->nbr_prog; i++) {
            if (corewar->prog[i].live == 1) {
                corewar->nbr_live++;
                corewar->prog[i].live = 0;
            }
        }
        if (corewar->nbr_live == 0) {
            corewar->cycle_to_die = 0;
        }
        if (corewar->cycle_to_die <= 0) {
            corewar->cycle_to_die = 0;
            corewar->check = 0;
            corewar->nbr_live = 0;
            corewar->nbr_cycle = 0;
            for (j = 0; j < corewar->nbr_prog; j++) {
                for (k = 0; k < MEM_SIZE; k++) {
                    corewar->prog[j].prog_mem[k] = 0;
                }
            }
        }
        corewar->nbr_cycle--;
    }
}

void corewar_init_vm(int nbr_cycle, int nbr_prog, int load_adress)
{
    t_corewar corewar;
    if (nbr_cycle == 0) corewar.nbr_cycle = CYCLE_TO_DIE;
    else corewar.nbr_cycle = nbr_cycle;
    if (nbr_prog == 0) corewar.nbr_prog = CYCLE_DELTA;
    else corewar.nbr_prog = nbr_prog;
    if (load_adress == 0) corewar.load_adress = NBR_LIVE;
    else corewar.load_adress = load_adress;
    corewar_loop(&corewar);
}

int main(int ac, char **av)
{
    error(ac, av);
    if ((ac == 2)
    && (!(my_strcmp(av[1], "-h")) || !(my_strcmp(av[1], "--help")))) {
        usage();
        exit(0);
    }
    if (ac < 3) {
        usage();
    }
    int nbr_cycle = 0; int nbr_prog = 0; int load_adress = 0;
    for (int i = 0; av[i] != NULL; i++) {
        nbr_cycle = check_usage("-dump", av, i);
        nbr_prog = check_usage("-n", av, i);
        load_adress = check_usage("-a", av, i);
    }
    corewar_init_vm(nbr_cycle, nbr_prog, load_adress);
    return (0);
}
