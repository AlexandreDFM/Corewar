/*
** EPITECH PROJECT, 2022
** LABELS_TREATMENT
** File description:
** Functions managing labels
*/

#include "../include/asm.h"

int check_label(t_prog *tmp)
{
    for (int i = 0; i < tmp->size; i++) {
        if (tmp->to_write[i] == INT_MIN && tmp->lab != NULL) {
            return i + 1;
        }
    }
    return 0;
}

int add_label(t_prog *tmp, int poslab)
{
    int nb_bytes = 0;
    for (t_prog *tmp2 = tmp; tmp2 != NULL; tmp2 = tmp2->next) {
        if (tmp2->nlab != NULL && !my_strcmp(tmp2->nlab, tmp->lab)) {
            tmp->to_write[poslab] = nb_bytes; break;
        } else {
            for (int i = 0; i < tmp2->size; i++) nb_bytes += tmp2->stock[i];
        }
    }
    if (tmp->to_write[poslab] != INT_MIN) return 1;
    nb_bytes = 0;
    for (t_prog *tmp2 = tmp->prev; tmp2 != NULL; tmp2 = tmp2->prev) {
        if (tmp2->nlab != NULL && !my_strcmp(tmp2->nlab, tmp->lab)) {
            tmp->to_write[poslab] = nb_bytes; break;
        } else {
            for (int i = 0; i < tmp2->size; i++) nb_bytes -= tmp2->stock[i];
        }
    }
    if (tmp->to_write[poslab] != INT_MIN) return 1;
    exit(84);
}

void label_management(t_core *core)
{
    int nb_labels = 0;
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        if (tmp->lab != NULL) {
            nb_labels++;
        }
    }
    for (int i = 0; i < nb_labels; i++) {
        for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
            i += check_label(tmp) > 0 ?
            add_label(tmp, check_label(tmp) - 1) : 0;
        }
    }
}
