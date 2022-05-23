/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for the bonus
*/

#include "../include/bonus.h"

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
    usage(); exit(84);
}

t_corewar *corewar_init(char **argv)
{
    t_corewar *corewar = malloc(sizeof(t_corewar));
    corewar->arena = init_vm();
    for (int i = 0; i < 4; i++)
        corewar->load_address[i] = 0, corewar->progs_nb[i] = 0;
    parse_flags(corewar, argv);
    corewar->winner = 0;
    corewar->one_death = 0;
    corewar->nbr_death = 0;
    return corewar;
}

void winner(t_corewar *corewar)
{
    t_list_champions *champion = corewar->champions;
    while (champion) {
        if (champion->infos[0] == corewar->winner) {
            // printf("The player %d(%s)has won.\n", champion->infos[0],
                // champion->name);
            break;
        }
        champion = champion->next;
    }
}

int main(int argc, char **argv)
{
    if (((argc == 2)
    && (!(my_strcmp(argv[1], "-h")) || !(my_strcmp(argv[1], "--help")))))
        usage();
    if (argc < 3)
        error();
    t_corewar *corewar = corewar_init(argv);
    if (read_champions(corewar, argv) == 84)
        return 84;
    launch_vm(corewar);
    winner(corewar);
    free_corewar(corewar);
    return (0);
}
