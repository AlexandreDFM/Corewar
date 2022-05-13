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

typedef enum CommandType {
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
} e_command;

typedef struct arguments {
    char type[MAX_ARGS_NUMBER];
    char *argv[MAX_ARGS_NUMBER];
} t_args;

typedef struct commands {
    struct commands *next;
    op_t *op;
} t_commands;

typedef struct core {
    char *name;
    char *comment;
    t_commands *commands;
} t_core;

typedef struct parse {
    int size;
    unsigned char *file;
} t_parse;

void encod_hexa(char *file, char *filename);
void encode_champion(char *buffer, char *fighter);

#endif /* ASM_H_ */
