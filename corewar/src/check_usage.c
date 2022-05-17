/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** check_usage
*/

#include "corewar.h"

int check_usage(char *command, char **av, int i)
{
    if (my_strcmp(av[i], command) == 0) {
        if (av[i + 1] == NULL) {
            usage(); exit(84);
        }
        if (my_getnbr(av[i + 1]) <= 0) {
            usage(); exit(84);
        }
        return my_atoi(av[i + 1]);
    }
    return 0;
}
