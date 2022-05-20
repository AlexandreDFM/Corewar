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
    while (*str++ != ' ');
    while (*str++ == ' ');
    str[my_strlen(str) - 1] = '\0';
    my_strcpy(dest, str);
}

void encode_champion(char *buffer, char *fighter)
{
    // INIT
    if (my_strstr(buffer, ".name") == NULL) exit(84);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    t_core *core = init_core(); char **array = my_strtwa(buffer, "\n");
    // HEADER && COMMENT
    int afterheader = 0;
    for (; array[afterheader] != NULL; afterheader++) {
        if (my_strstr(array[afterheader], "#")) continue;
        if (my_strstr(array[afterheader], NAME_CMD_STRING))
            core_header(core->header.prog_name, array[afterheader]);
        else if (my_strstr(array[afterheader], COMMENT_CMD_STRING))
            core_header(core->header.comment, array[afterheader]);
        else {
            break;
        }
    }
    // CLEAR TABS AND SPACES
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][0] == ' ') {
                j = 0;
                while (array[i][j + 1] != '\0') {
                    array[i][j] = array[i][j + 1];
                    j++;
                }
                array[i][j] = '\0';
                j = 0;
            }
        }
    }
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (j != 0 && array[i][j - 1] == ',' && array[i][j] == ' ') {
                while (array[i][j + 1] != '\0') {
                    array[i][j++] = array[i][j + 1];
                }
                array[i][j] = '\0';
                j = 0;
            }
        }
    }
    char ***bigtab = malloc(sizeof(char **) * (my_tablen(array) + 1));
    for (int i = 0; i < my_tablen(array); i++)
        bigtab[i] = my_strtwa(array[i], " ");
    bigtab[my_tablen(array)] = NULL;
    my_free_array(array);
    // COMMANDS

    // for (int i = 0; bigtab[i] != NULL; i++) {
    //     for (int j = 0; bigtab[i][j] != NULL; j++) {
    //         printf("%s\n", bigtab[i][j]);
    //     }
    // }

    for (int i = afterheader; bigtab[i] != NULL; i++)
        parse_line_prog(bigtab[i], core);

    // CHECK LABEL_ERROR
    label_error(core->prog);
    // PROG SIZE
    for (t_prog *tmp = core->prog; tmp != NULL; tmp = tmp->next) {
        for (int i = 0; i < tmp->size; i++) {
            core->header.prog_size += tmp->stock[i];
        }
    }
    // LABELS
    label_management(core);

    // DEBUG
    // printf("\n");
    // t_prog *tmp = core->prog;
    // for (; tmp != NULL; tmp = tmp->next) {
    //     for (int i = 0; i < tmp->size; i++) {
    //         printf("%x,\t", tmp->to_write[i]);
    //     }
    //     printf("\n");
    //     for (int i = 0; i < tmp->size; i++) {
    //         printf("%d,\t", tmp->stock[i]);
    //     }
    //     printf("\n");
    // }

    // WRITING
    write_file(core, fighter);
    // FREE
    for (int i = 0; bigtab[i] != NULL; i++)
        my_free_array(bigtab[i]);
    free(bigtab);
    my_free_core(core);
}
