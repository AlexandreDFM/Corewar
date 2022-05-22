/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

void check_dump(t_corewar *corewar, char **av, int i)
{
    if (!my_strcmp(av[i], DUMP)) {
        if (atoi(av[i + 1]) > 0)
            corewar->arena->cycle_to_die = my_atoi(av[i + 1]);
        else
            exit(84);
    }
}

void check_address(t_corewar *corewar, char **av, int i, int nb_champs)
{
    if (!my_strcmp(av[i], ADDRESS)) {
        if ((my_atoi(av[i + 1]) >= 0 && my_atoi(av[i + 1]) <= MEM_SIZE
        && my_strstr(av[i + 2], ".cor")) || ((!my_strcmp(av[i + 2], "-n")
        && my_strstr(av[i + 4], ".cor") && my_atoi(av[i + 1]) >= 0
        && my_atoi(av[i + 1]) <= MEM_SIZE))) {
            corewar->load_address[nb_champs - 1] = my_atoi(av[i + 1]);
        } else
            exit(84);
    }
}

void check_prog_nb(t_corewar *corewar, char **av, int i, int nb_champs)
{
    if (!my_strcmp(av[i], PROG_NB)) {
        if ((my_atoi(av[i + 1]) > 0 && my_strstr(av[i + 2], ".cor"))
        || ((!my_strcmp(av[i + 2], "-a") && my_strstr(av[i + 4], ".cor")
        && my_atoi(av[i + 1]) > 0))) {
            corewar->progs_nb[nb_champs - 1] = my_atoi(av[i + 1]);
        } else
            exit(84);
    }
}

void parse_flags(t_corewar *corewar, char **av)
{
    int nb_champs = 0, count = 1;
    for (int i = 0; av[i] != NULL; ++i)
        if (my_strstr(av[i], ".cor")) nb_champs++;
    for (int i = 0; av[i] != NULL; ++i) {
        if (my_strstr(av[i], ".cor"))
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
