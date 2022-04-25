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

int main(int ac, char **av)
{
    error(ac, av);
    if ((ac == 2)
    && (!(my_strcmp(av[1], "-h")) || !(my_strcmp(av[1], "--help")))) {
        usage();
        exit(0);
    }
    return (0);
}
