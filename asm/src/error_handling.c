/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** error_handling
*/

#include "../include/asm.h"

void label_error(t_prog *prog)
{
    int counter = 0;
    for (t_prog *p = prog; p != NULL; p = p->next) {
        if (p->lab == NULL) continue;
        for (int i = 0; p->lab[i] != ':' && p->lab[i] != '\0'; i++)
            counter += check_char(p->lab[i], LABEL_CHARS);
        if (counter == 0) exit(84);
        counter = 0;
    }
}
