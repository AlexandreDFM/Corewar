/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for asm
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
