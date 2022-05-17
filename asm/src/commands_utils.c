/*
** EPITECH PROJECT, 2022
** COMMANDS_UTILS
** File description:
** Utilities functions for t_commands struct
*/

#include "../include/asm.h"

void push_back_commands(t_commands *head, t_commands *node)
{
    t_commands *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

void push_back_counter(t_counter *head, t_counter *node)
{
    t_counter *tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}
