/*
** EPITECH PROJECT, 2022
** ASM_H_
** File description:
** Header file for asm
*/

#include "proto.h"
#include "op.h"

#ifndef ASM_H_
    #define ASM_H_

typedef struct Prog {
    struct Prog *next;
    int *to_write;
    int *stock;
    int size;
} t_prog;

typedef struct Core {
    header_t header;
    t_prog *prog;
} t_core;

char get_op(char *command);

int my_stocktostring(char opcode, char *str);
int my_argtostring(char *str);
int calcul_pcb(char **arguments);

void encod_hexa(char *file, char *filename);
void encode_champion(char *buffer, char *fighter);

void write_file(t_core *core, char *fighter);
void parse_line_prog(char **line, t_core *core);
void push_back_prog(t_prog **head, t_prog *node);

void error(int ac, char **av);
void usage(void);

#endif /* ASM_H_ */
