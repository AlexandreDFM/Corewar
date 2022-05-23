/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/bonus.h"

void check_dump(t_corewar *corewar, char **av, int i)
{
    if (!strcmp(av[i], DUMP)) {
        if (atoi(av[i + 1]) > 0)
            corewar->arena->cycle_to_die = atoi(av[i + 1]);
        else
            exit(84);
    }
}

void check_address(t_corewar *corewar, char **av, int i, int nb_champs)
{
    if (!strcmp(av[i], ADDRESS)) {
        if ((atoi(av[i + 1]) >= 0 && atoi(av[i + 1]) <= MEM_SIZE
        && strstr(av[i + 2], ".cor")) || ((!strcmp(av[i + 2], "-n")
        && strstr(av[i + 4], ".cor") && atoi(av[i + 1]) >= 0
        && atoi(av[i + 1]) <= MEM_SIZE))) {
            corewar->load_address[nb_champs - 1] = atoi(av[i + 1]);
        } else
            exit(84);
    }
}

void check_prog_nb(t_corewar *corewar, char **av, int i, int nb_champs)
{
    if (!strcmp(av[i], PROG_NB)) {
        if ((atoi(av[i + 1]) > 0 && strstr(av[i + 2], ".cor"))
        || ((!strcmp(av[i + 2], "-a") && strstr(av[i + 4], ".cor")
        && atoi(av[i + 1]) > 0))) {
            corewar->progs_nb[nb_champs - 1] = atoi(av[i + 1]);
        } else
            exit(84);
    }
}

void parse_flags(t_corewar *corewar, char **av)
{
    int nb_champs = 0, count = 1;
    for (int i = 0; av[i] != NULL; ++i)
        if (strstr(av[i], ".cor")) nb_champs++;
    for (int i = 0; av[i] != NULL; ++i) {
        if (strstr(av[i], ".cor"))
            count++;
        check_dump(corewar, av, i);
        check_address(corewar, av, i, count);
        check_prog_nb(corewar, av, i, count);
    }
    for (int i = 0; i < nb_champs; i++) {
        for (int j = 0; j < nb_champs; j++) {
            (j != i && corewar->progs_nb[i] == corewar->progs_nb[j]
            && corewar->progs_nb[i] != 0 && corewar->progs_nb[j] != 0) ?
            exit(84) : 0;
        }
    }
}
