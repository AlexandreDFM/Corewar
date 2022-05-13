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
    core->name = NULL;
    core->comment = NULL;
    core->commands = NULL;
    return (core);
}

char *core_header(char *str)
{
    char *tmp = my_strstr(str, "\""); tmp[my_strlen(tmp) - 1] = '\0'; tmp++;
    return(my_strcpy(malloc(sizeof(char) * (my_strlen(tmp) + 1)), tmp));
}

void find_commands(char *str, t_core *core)
{
    t_commands *command = NULL;
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strstr(str, op_tab[i].mnemonique) != NULL) {
            create_commands(str[i]);
        }
        push
    }
}

void encode_champion(char *buffer, char *fighter)
{
    // PARSING
    char **array = my_strtwa(buffer, "\n"); t_core *core = init_core();
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strstr(array[i], NAME_CMD_STRING))
            core->name = core_header(array[i]);
        else if (my_strstr(array[i], COMMENT_CMD_STRING))
            core->comment = core_header(array[i]);
        else
            find_commands(array[i], core);
    }
    free_array(array);
    // CREATING THE .cor FILE
}
