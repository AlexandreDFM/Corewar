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

t_corewar *corewar_init(char **av)
{
    t_corewar *corewar = malloc(sizeof(t_corewar));
    corewar->arena = init_vm();
    for (int i = 0; i < 4; i++)
        corewar->load_address[i] = 0, corewar->progs_nb[i] = 0;
    parse_flags(corewar, av);
    corewar->winner = 0;
    corewar->one_death = 0;
    return corewar;
}

int main(int ac, char **av)
{
    if (((ac == 2)
    && (!(my_strcmp(av[1], "-h")) || !(my_strcmp(av[1], "--help")))))
        usage();
    if (ac < 3)
        error();
    t_corewar *corewar = corewar_init(av);
    if (read_champions(corewar, av) == 84)
        return 84;
    launch_vm(corewar);
    free_corewar(corewar);
    return (0);
}
