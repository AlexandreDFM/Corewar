/*
** EPITECH PROJECT, 2022
** ASM_UTILS
** File description:
** Utils functions for asm
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

int my_stocktostring(char opcode, char *str)
{
    int i = 1;
    if (opcode == 9 || opcode == 10 || opcode == 11 ||
    opcode == 12 || opcode == 14 || opcode == 15)
        i = 2;
    if (my_strncmp(str, "r", 1) == 0) return (REG_SIZE);
    if (my_strncmp(str, "%", 1) == 0) return (DIR_SIZE / i);
    return IND_SIZE;
}

int my_argtostring(char *str)
{
    if (my_strncmp(str, "r", 1) == 0) return (my_atoi(++str));
    if (my_strncmp(str, "%", 1) == 0) return (my_atoi(++str));
    return (my_atoi(str));
}

int calcul_pcb(char **arguments)
{
    int pcb = 0, i = 0;
    char *str = malloc(sizeof(char) * 9);
    my_memset(str, 0, 9);
    for (; arguments[i] != NULL; i++) {
        if (my_strncmp(arguments[i], "r", 1) == 0) my_strcat(str, "01");
        else if (my_strncmp(arguments[i], "%", 1) == 0) my_strcat(str, "10");
        else my_strcat(str, "11");
    }
    for (; my_strlen(str) < 8; i++)
        my_strcat(str, "0");
    pcb = my_bintohex(str);
    return (pcb);
}

void push_back_prog(t_prog **head, t_prog *node)
{
    if (*head == NULL) {
        *head = node;
        return;
    }
    t_prog *tmp = *head;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
}
