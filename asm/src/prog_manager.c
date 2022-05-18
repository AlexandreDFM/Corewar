/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** prog_manager
*/

#include "../include/asm.h"

void create_line_prog(char opcode, char **args, t_core *core)
{
    t_prog *p = malloc(sizeof(t_prog)); p->next = NULL; p->prev = NULL;
    int size = my_tablen(args);
    if (opcode != 1 && opcode != 12 && opcode != 9 && opcode != 15) {
        p->size = size + 2; p->to_write = malloc(sizeof(int) * (p->size));
        p->stock = malloc(sizeof(int) * (p->size));
        p->to_write[0] = opcode; p->stock[0] = 1;
        p->to_write[1] = calcul_pcb(args); p->stock[1] = 1;
        for (int i = 0; i < size; i++) {
            p->to_write[i + 2] = my_argtostring(args[i]);
            p->stock[i + 2] = my_stocktostring(opcode, args[i]);
        }
    } else {
        p->size = size + 1; p->to_write = malloc(sizeof(int) * (p->size));
        p->stock = malloc(sizeof(int) * (p->size));
        p->to_write[0] = opcode; p->stock[0] = 1;
        for (int i = 0; i < size; i++) {
            p->to_write[i + 1] = my_argtostring(args[i]);
            p->stock[i + 1] = my_stocktostring(opcode, args[i]);
        }
    } push_prog(&core->prog, p);
}

void parse_line_prog(char **line, t_core *core)
{
    if (line[1] == NULL || !my_strcmp(line[0], "\n")) return;
    char opcode = get_op(line[0]);
    char **args = my_strtwa(line[1], ",");
    if (my_strstr(line[0], ":")) {
        opcode = get_op(line[1]);
        my_free_array(args);
        args = my_strtwa(line[2], ",");
        create_line_prog(opcode, args, core);
    } else {
        create_line_prog(opcode, args, core);
    }
    my_free_array(args);
}
