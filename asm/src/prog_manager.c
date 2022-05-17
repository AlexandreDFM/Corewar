/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** prog_manager
*/

#include "./include/asm.h"

char get_op(char *command)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(command, op_tab[i].mnemonique) == 0)
            return (op_tab[i].code);
    }
}

void parse_line_prog(char *line, t_core *core)
{
    char **line_parse = my_strtwa(line, " ");
    char **arg_parse = my_strtwa(line_parse[1], ",");
    char opcode = get_op(line_parse[0]);
    char *commandarg = get_command_arg(opcode, arg_parse);
}
