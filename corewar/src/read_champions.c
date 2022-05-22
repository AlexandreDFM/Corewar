/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../include/corewar.h"

void set_data_champion(t_list_champions *new, unsigned char *file, int i)
{
    new->file = file;
    new->name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    my_memset(new->name, '\0', PROG_NAME_LENGTH - 1);
    new->comment = malloc(sizeof(char) * COMMENT_LENGTH);
    my_memset(new->comment, '\0', COMMENT_LENGTH - 1);
    new->command = NULL;
    new->next = NULL;
    new->prev = NULL;
    new->reg[0] = i;
    new->infos[0] = i;
    new->infos[2] = 0;
    new->infos[3] = 0;
    new->infos[4] = 0;
    new->prog_size = 0;
}

void push_back_champion(t_list_champions **head, unsigned char *file, int i)
{
    t_list_champions *new = malloc(sizeof(t_list_champions));
    t_list_champions *tmp = *head;
    set_data_champion(new, file, i);
    if (!tmp) {
        *head = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

int read_champions(t_corewar *corewar, char **av)
{
    corewar->champions = NULL;
    for (int i = 1; av[i] != NULL; i++, corewar->arena->nbr_prog++) {
        if (corewar->arena->nbr_prog > MAX_PLAYER) {
            my_putstr("Too much champions\n");
            return 84;
        }
        push_back_champion(&corewar->champions,
            open_file(av[i], sizeof(BYTE) * sizeof(header_t)), i);
    }
    t_list_champions *champions = corewar->champions;
    while (champions) {
        if_magic(champions);
        parse_name_champion(champions);
        parse_prog_size(champions);
        parse_comment(champions);
        parse_command(champions);
        champions = champions->next;
    }
    return 0;
}
