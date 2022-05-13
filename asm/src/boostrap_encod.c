/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** boostrap_encod
*/

#include "../include/asm.h"

void instruction(t_core *corewar, char *line, e_var t, char operator)
{
    t_core *tmp = corewar;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = malloc(sizeof(t_core)); tmp = tmp->next;
    tmp->operator = operator; tmp->t = t;
    if (t == INT) {
        char *slice = my_slice_array(0, line, 4);
        char *firstnb = my_strdup_to_char(slice, " ");
        char *slice2 = my_slice_array(0, slice, pos_char(slice, " ") + 1);
        char *secondnb = my_strdup_to_char(slice2, " ");
        int nb1 = my_atoi(firstnb); int nb2 = my_atoi(secondnb);
        tmp->data1 = malloc(sizeof(nb1)); tmp->data2 = malloc(sizeof(nb2));
        my_memcpy(tmp->data1, &nb1, sizeof(nb1));
        my_memcpy(tmp->data2, &nb2, sizeof(nb2));
        free(slice); free(slice2); free(firstnb);
        free(secondnb);
    } else if (t == CHAR) {
        char *slice = my_slice_array(0, line, 4);
        tmp->size = my_strlen(slice);
        tmp->data1 = malloc(my_strlen(slice));
        my_memcpy(tmp->data1, slice, my_strlen(slice)); free(slice);
    } tmp->next = NULL;
}

void print_instruction(t_core *corewar, int fd)
{
    t_core *core = corewar;
    while (core != NULL) {
        if (core->data1 == NULL) {
            core = core->next; continue;
        }
        if (core->t == INT) {
            write(fd, &core->operator, 1);
            write(fd, core->data1, core->t); write(fd, core->data2, core->t);
            free(core->data1); free(core->data2);
        } else if (core->t == CHAR) {
            write(fd, &core->operator, 1);
            write(fd, &core->size, 4);
            write(fd, core->data1, core->size);
            free(core->data1);
        } core = core->next;
    }
    t_core *tmp = corewar, *tmp2 = corewar->next;
    for (; tmp2 != NULL; tmp = tmp2, tmp2 = tmp->next) free(tmp);
    free(tmp);
}

void encod_hexa(char *file, char *filename)
{
    t_core *c = malloc(sizeof(t_core));
    c->data1 = NULL; c->next = NULL;
    int fd = open(my_strcat(filename, ".cor"), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char **f = my_strtwa(file, "\n");
    for (int i = 0; f[i] != NULL; i++) {
        if (!(my_strncmp(f[i], "add", 3))) instruction(c, f[i], INT, 0x01);
        if (!(my_strncmp(f[i], "sub", 3))) instruction(c, f[i], INT, 0x02);
        if (!(my_strncmp(f[i], "mul", 3))) instruction(c, f[i], INT, 0x03);
        if (!(my_strncmp(f[i], "put", 3))) instruction(c, f[i], CHAR, 0x04);
    }
    print_instruction(c, fd);
    close(fd);
    my_free_array(f);
}

