/*
** EPITECH PROJECT, 2022
** ERROR_USAGE
** File description:
** Error and usage functions
*/

#include "../include/asm.h"

void usage(void)
{
    my_putstr(RED BOLD UNDERLINE "USAGE\n" RESET);
    my_putstr("\t./asm file_name[.s]\n\n");
    my_putstr(BLUE BOLD UNDERLINE "DESCRIPTION\n" RESET);
    my_putstr("\tfile_name\tfile in assembly language to be ");
    my_putstr("translated into file_name.cor, an\n");
    my_putstr("\t\t\texecutable in the Virtual Machine.\n");
    my_putstr("\t-h --help\tdisplay this help.\n");
    return;
}

void error(int ac, char **av)
{
    if (ac == 1)
        usage(), exit(84);
    for (int i = 1; i < ac; i++) {
        if (av[i][my_strlen(av[i]) - 1] != 's'
        || av[i][my_strlen(av[i]) - 2] != '.')
            my_putstr_error("Bad file extension : need .s\n");
    }
}
