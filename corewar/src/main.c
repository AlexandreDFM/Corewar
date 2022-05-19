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
    exit(0);
}

void error(void)
{
    usage();
    exit(84);
}

t_corewar *corewar_init_vm(char **av)
{
    t_corewar *corewar = malloc(sizeof(t_corewar));
//    parse_flags(av);
    corewar->nbr_cycle = CYCLE_TO_DIE;
    corewar->nbr_prog = 2;
    return corewar;
}

int main(int ac, char **av)
{
    if (((ac == 2)
    && (!(my_strcmp(av[1], "-h")) || !(my_strcmp(av[1], "--help")))))
        usage();
    if (ac < 3)
        error();
    t_corewar *corewar = corewar_init_vm(av);
    read_champions(corewar, av);
    return (0);
}
