/*
** EPITECH PROJECT, 2022
** FREE
** File description:
** Functions to free our work
*/

#include "../include/asm.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void free_op(op_t *op)
{
    free(op->mnemonique);
    free(op->comment);
    free(op);
}

void free_command(t_commands *list)
{
    t_commands *tmp = list->next;
    while (tmp != NULL) {
        free_op(list->op);
        free(list);
        list = tmp;
        tmp = tmp->next;
    }
    free(tmp);
}

void free_core(t_core *core)
{
    free(core->name);
    free(core->comment);
    free_command(core->commands);
    free(core);
}
