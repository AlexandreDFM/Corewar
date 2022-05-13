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

typedef enum VarType {
    CHAR = 1,
    INT = 4,
} e_var;

typedef enum ChampionsType {
    LIVE = 1,
    LD = 2,
    ST = 3,
    ADD = 4,
    SUB = 5,
    AND = 6,
    OR = 7,
    XOR = 8,
    ZJMP = 9,
    LDI = 10,
    STI = 11,
    FORK = 12,
    LLD = 13,
    LLDI = 14,
    LFORK = 15,
    AFF = 16,
} e_champions;

typedef struct Arguments {
    char type[MAX_ARGS_NUMBER];
    char *argv[MAX_ARGS_NUMBER];
} t_args;

typedef struct Commands {
    struct Commands *next;
    t_args arguments;
    char *binary;
    char *line;
    int binary_size;
    char command_code;
} t_commands;


typedef struct core {
    e_var t;
    int size;
    char operator;
    void *data1;
    void *data2;
    struct core *next;
} t_core;

typedef struct parse {
    int size;
    unsigned char *file;
} t_parse;

void encod_hexa(char *file, char *filename);

#endif /* ASM_H_ */
