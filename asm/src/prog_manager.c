/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** prog_manager
*/

#include "../include/asm.h"

char get_op(char *command)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(command, op_tab[i].mnemonique) == 0)
            return (op_tab[i].code);
    }

    return (0);
}

int my_gethexa(char *str)
{
    
}

t_prog *create_line_prog(char opcode, char **arguments)
{
    t_prog *prog = malloc(sizeof(t_prog));
    int size_arg = my_tablen(arguments);
    prog->to_write = malloc(sizeof(int) * (size_arg + 1));
    prog->to_write[0] = opcode;
    for (int i = 0; i < size_arg; i++)
        prog->to_write[i + 1] = my_gethexa(arguments[i]);
    for (t_prog *tmp = prog; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; i < (size_arg + 1); i++) {
            printf("%d, ", tmp->to_write[i]);
        }
    }
    exit(0);
    return (prog);
}

void push_back_prog(t_prog *head, t_prog *node)
{
    if (head == NULL) {
        head = node;
        return;
    }
    t_prog *tmp = head;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
}

void parse_line_prog(char *line, t_core *core)
{
    // printf("%s\n", line);
    if (!my_strstr(line, " ")) return;
    char **line_parse = my_strtwa(line, " ");
    char **arg_parse = my_strtwa(line_parse[1], ",");
    char opcode = get_op(line_parse[0]);
    
    t_prog *prog = create_line_prog(opcode, arg_parse);
    // push_back_prog(core->prog, prog);
    // to_write[0] -> opcode -> 0x0b
    // stock[0] -> sizeof(opcode) -> 1
    // push tmp dans core->prog

    free_array(line_parse); free_array(arg_parse);

    exit(0);
}
