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
    core->magic = COREWAR_EXEC_MAGIC;
    core->name = NULL;
    core->comment = NULL;
    core->commands = NULL;
    return (core);
}

char *core_header(char *str)
{
    char *tmp = my_strstr(str, "\""); tmp[my_strlen(tmp) - 1] = '\0'; tmp++;
    return (my_strcpy(malloc(sizeof(char) * (my_strlen(tmp) + 1)), tmp));
}

void encode_champion(char *buffer, char *fighter)
{
    // PARSING
    char **array = my_strtwa(buffer, "\n"); t_core *core = init_core();
    t_commands *command = NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strstr(array[i], "#") != NULL) continue;
        if (my_strstr(array[i], NAME_CMD_STRING))
            core->name = core_header(array[i]);
        else if (my_strstr(array[i], COMMENT_CMD_STRING))
            core->comment = core_header(array[i]);
        else {
            command = find_commands(array[i]);
            if (core->commands != NULL && command != NULL)
                push_back_commands(core->commands, command);
            if (core->commands == NULL && command != NULL)
                core->commands = command;
        }
    }
    // WRITING
    write_file(core, fighter);
    // free(core);
    free_array(array);
    // CREATING THE .cor FILE
}
