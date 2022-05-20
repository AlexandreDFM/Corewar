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
    core->header.magic = COREWAR_EXEC_MAGIC;
    core->header.prog_size = 0;
    core->prog = NULL;
    return (core);
}

void core_header(char *dest, char *str)
{
    while (*str++ == '\t');
    while (*str++ == ' ');
    while (*str++ != ' ');
    while (*str++ == ' ');
    str[my_strlen(str) - 1] = '\0';
    my_strcpy(dest, str);
}

void get_name_and_comment(char **array, t_core *core, int *afterheader)
{
    int i = *afterheader;
    for (; array[i] != NULL; i++) {
        if (my_strstr(array[i], "#")) continue;
        if (my_strstr(array[i], NAME_CMD_STRING))
            core_header(core->header.prog_name, array[i]);
        else if (my_strstr(array[i], COMMENT_CMD_STRING))
            core_header(core->header.comment, array[i]);
        else {
            *afterheader = i;
            break;
        }
    }
}

void encode_champion(char *buffer, char *fighter)
{
    if (my_strstr(buffer, ".name") == NULL) exit(84);
    clean_buffer(buffer); t_core *core = init_core();
    char **array = my_strtwa(buffer, "\n"); int afterheader = 0;
    get_name_and_comment(array, core, &afterheader); clean_array(array);
    char ***btab = malloc(sizeof(char **) * (my_tablen(array) + 1));
    for (int i = 0; i < my_tablen(array); i++)
        btab[i] = my_strtwa(array[i], " ");
    btab[my_tablen(array)] = NULL; my_free_array(array);
    for (int i = afterheader; btab[i] != NULL; i++) {
        parse_line_prog(btab[i], core);
    }
    label_error(core->prog);
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; i < tmp->size; i++)
            core->header.prog_size += tmp->stock[i];
    }
    label_management(core); write_file(core, fighter);
    for (int i = 0; btab[i] != NULL; i++) my_free_array(btab[i]);
    free(btab); my_free_core(core);
}
