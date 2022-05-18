/*
** EPITECH PROJECT, 2022
** LABELS_MANAGER
** File description:
** Functions managing labels
*/

#include "../include/asm.h"

void found_my_label(char ***bigtab, t_prog **aprog, int i)
{
    for (int j = 0; j < ; j++) {
        
    }
}

void create_line_label(char ***bigtab, t_core *core)
{
    int nb_labels = 0;
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; i < tmp->size; i++) {
            nb_labels += (tmp->to_write[i] == -1) ? 1 : 0;
        }
    }
    for (int i = 0; i < nb_labels; i++) {
        for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
            if (tmp->to_write[i] == -1) {
                found_my_label(bigtab, &tmp, i);
            }
        }
    }
}

void parse_labels_prog(t_core *core, char ***btab, char **l, Vector2i vec)
{
    if (l[1] == NULL || !my_strcmp(l[0], "\n")) return;
    char opcode = get_op(l[0]);
    char **args = my_strtwa(l[1], ",");
    if (my_strstr(l[0], ":")) {
        opcode = get_op(l[1]);
        my_free_array(args);
        args = my_strtwa(l[2], ",");
        create_line_prog(opcode, args, core);
    } else {
        create_line_prog(opcode, args, core);
    }
    my_free_array(args);
}
