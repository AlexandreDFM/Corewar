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
    node->next = NULL;
    if (!tmp) {
        head = node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}
