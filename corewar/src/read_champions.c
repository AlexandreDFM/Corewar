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
    new->number = i;
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

void if_magic(t_list_champions *champions)
{
    int magic = 0;
    for (int i = 1; i < 4; i++)
        magic += switch_endian(champions->file[i] << (BYTE * i));
    if (magic != COREWAR_EXEC_MAGIC) {
        my_putstr("Learn to use magic\n");
        exit(84);
    }
}

void read_champions(t_corewar *corewar, char **av)
{
    corewar->champions = NULL;
    for (int i = 1; i < corewar->nbr_prog + 1; i++)
        push_back_champion(&corewar->champions,
            open_file(av[i], sizeof(header_t)), i);
    t_list_champions *champions = corewar->champions;
    while (champions) {
        printf("champion%d\n", champions->number);
        if_magic(champions);
        parse_name_champion(champions);
        parse_prog_size(champions);
        parse_comment(champions);
        champions = champions->next;
        if (champions)
            printf("\n");
    }
}