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
    if (ac == 1)
        usage(), exit(84);
    for (int i = 1; i < ac; i++) {
        if (av[i][my_strlen(av[i]) - 1] != 's'
        || av[i][my_strlen(av[i]) - 2] != '.')
            my_putstr_error("Bad file extension : need .s\n");
    }
}

char *create_fighter(char *p)
{
    for (int i = 0, j = 1; p[i++]; j++) if (p[i] == '/') p += j, j = 1, i = 0;
    char *xd = my_strcat(my_revstr(my_strstr(my_revstr(++p), ".")), "cor");
    return (my_strcpy(malloc(sizeof(char) * (my_strlen(xd) + 1)), xd));
}

void analyse_champions(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        my_putstr_error("Can't open file: ");
        my_putstr_error(path);
        my_putstr_error("\n");
        close(fd); return;
    }
    close(fd);
    char *buffer = open_file(path, len_file(path));
    char *fighter = create_fighter(path);
    encode_champion(buffer, fighter);
    free(buffer);
}

void avengers_assemble(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        analyse_champions(av[i]);
}

int main(int ac, char **av)
{
    if ((ac == 2)
    && (!(my_strcmp(av[1], "-h")) || !(my_strcmp(av[1], "--help")))) {
        usage();
        exit(0);
    }
    error(ac, av);
    avengers_assemble(ac, av);
    return (0);
}
