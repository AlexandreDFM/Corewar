/*
** EPITECH PROJECT, 2022
** ASM_H_
** File description:
** Header file for asm
*/

#include "my.h"
#include "op.h"

#ifndef ASM_H_
    #define ASM_H_

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

#endif /* ASM_H_ */
