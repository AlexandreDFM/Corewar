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
    int size = 0;
    if (my_strstr(str, "\"") == NULL) exit(84);
    if (my_strstr(str, NAME_CMD_STRING) != NULL) {
        if (my_strlen(str) <= (my_strlen(NAME_CMD_STRING) + 3)) exit(84);
        size = PROG_NAME_LENGTH + 1;
    } else if (my_strstr(str, COMMENT_CMD_STRING) != NULL) {
        (my_strlen(str) <= (my_strlen(NAME_CMD_STRING) + 3)) ? exit(84) : 0;
        size = COMMENT_LENGTH + 1;
    } else {
        exit(84);
    }
    while (*str++ == '\t');
    while (*str++ == ' ');
    while (*str++ != ' ');
    while (*str++ == ' ');
    str[my_strlen(str) - 1] = '\0';
    my_strcpy(dest, str);
    if (my_strstr(dest, "\"")) exit(84);
    if (my_strlen(dest) >= size) exit(84);
}

void get_name_and_comment(char **array, t_core *core, int *afterheader)
{
    int i = *afterheader, j = 0, k = 0;
    for (; array[i] != NULL; i++) {
        if (my_strstr(array[i], "#") && (j == 0 || k == 0)) exit(84);
        if (my_strstr(array[i], "#")) continue;
        if (!my_strstr(array[i], NAME_CMD_STRING) &&
        !my_strstr(array[i], COMMENT_CMD_STRING) && (j == 0 || k == 0)) {
            exit(84);
        }
        if (my_strstr(array[i], NAME_CMD_STRING)) {
            core_header(core->header.prog_name, array[i]); j++;
        } else if (my_strstr(array[i], COMMENT_CMD_STRING)) {
            core_header(core->header.comment, array[i]); k++;
        } else {
            *afterheader = i; break;
        }
    }
    if (j > 1 || k > 1) exit(84);
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
