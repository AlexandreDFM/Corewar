/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** my_free_utils
*/

#include "../include/asm.h"

void my_free_core(t_core *core)
{
    t_prog *tmp = core->prog, *tmp2 = core->prog->next;
    for (; tmp2 != NULL; tmp = tmp2, tmp2 = tmp->next) {
        free(tmp->to_write);
        free(tmp->stock);
        free(tmp);
    }
    free(tmp->to_write); free(tmp->stock); free(tmp);
    free(core);
}
