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

typedef struct Vector2i_s {
    int x;
    int y;
} Vector2i;

typedef struct Prog {
    struct Prog *prev;
    struct Prog *next;
    bool print;
    int *to_write;
    int *stock;
    int size;
    char *lab;
    char *nlab;
} t_prog;

typedef struct Core {
    header_t header;
    t_prog *prog;
} t_core;

char get_op(char *command);

int my_stocktostring(char opcode, char *str);
int my_argtostring(char *str, t_prog *p);
int calcul_pcb(char **arguments);
int little_endian_to_big_endian(int x, int nb_bytes);

void encod_hexa(char *file, char *filename);
void encode_champion(char *buffer, char *fighter);

void write_file(t_core *core, char *fighter);
void parse_line_prog(char **line, t_core *core);
void push_prog(t_prog **head, t_prog *node);
void label_management(t_core *core);
void my_free_core(t_core *core);

void error(int ac, char **av);
void usage(void);

#endif /* ASM_H_ */
