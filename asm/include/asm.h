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
} t_prog;

typedef struct Core {
    header_t header;
    t_prog *prog;
} t_core;

void encod_hexa(char *file, char *filename);
void encode_champion(char *buffer, char *fighter);

void write_file(t_core *core, char *fighter);

#endif /* ASM_H_ */
