/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** create_ll
*/

#include "../include/asm.h"

t_commands *create_command(op_t *op)
{
    t_commands *command = malloc(sizeof(t_commands));
    command->next = NULL;
    command->op = op;
    return (command);
}

t_counter *create_counter(op_t *command, int sizeline)
{
    t_counter *counter = malloc(sizeof(t_counter));
    counter->next = NULL;
    counter->command = command;
    counter->sizeline = sizeline;
    return (counter);
}
