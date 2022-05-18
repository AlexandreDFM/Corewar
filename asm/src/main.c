/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for asm
*/

#include "../include/asm.h"

char *create_fighter(char *p)
{
    for (int i = 0, j = 1; p[i++]; j++) if (p[i] == '/') p += j, j = 1, i = 0;
    char *xd = my_strcat(my_revstr(my_strstr(my_revstr(p), ".")), "cor");
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
    free(buffer); free(fighter);
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
