/*
** EPITECH PROJECT, 2022
** ENCODER
** File description:
** File encoding champions
*/

#include "../include/asm.h"

t_core *init_core(void)
{
    t_core *core = malloc(sizeof(t_core));
    core->prog = malloc(sizeof(t_prog));
    return (core);
}

void core_header(char *dest, char *str)
{
    while (*str++ != ' '); str++;
    str[my_strlen(str) - 1] = '\0';
    my_strcpy(dest, str);
}

void encode_champion(char *buffer, char *fighter)
{
    // INIT
    char **array = my_strtwa(buffer, "\n"); t_core *core = init_core();

    // HEADER && COMMENT
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strstr(array[i], "#")) continue;
        if (my_strstr(array[i], NAME_CMD_STRING))
            core_header(core->header.prog_name, array[i]);
        else if (my_strstr(array[i], COMMENT_CMD_STRING))
            core_header(core->header.comment, array[i]);
        else
            break;
    }
    // COMMANDS
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strstr(array[i], "#")) continue;
        if (my_strstr(array[i], NAME_CMD_STRING)) continue;
        if (my_strstr(array[i], COMMENT_CMD_STRING)) continue;
        parse_line_prog(array[i], core);
    }
    return;
    // WRITING
    write_file(core, fighter);

    // FREE
    free_array(array); free(core);
}
