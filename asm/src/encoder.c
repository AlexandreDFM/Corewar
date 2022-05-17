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
    return(my_strcpy(malloc(sizeof(char) * (my_strlen(tmp) + 1)), tmp));
}

t_commands *create_command(op_t *op)
{
    t_commands *command = malloc(sizeof(t_commands));
    command->next = NULL;
    command->op = op;
    return (command);
}

t_counter *create_counter(char *command, int sizeline)
{
    t_counter *counter = malloc(sizeof(t_counter));
    counter->next = NULL;
    counter->command = command;
    counter->sizeline = sizeline;
    return (counter);
}

t_counter *sort_counter(t_counter *counter)
{
    t_counter *tmp = counter;
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->sizeline > tmp->next->sizeline) {
            t_counter *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            tmp2->next = tmp;
            tmp = tmp2;
        }
        tmp = tmp->next;
    }
    t_counter *tmp_print = counter;
    while (tmp_print != NULL) {
        printf("TURN : %d\n", 1);
        printf("%s\n", tmp_print->command);
        printf("%d\n", tmp_print->sizeline);
        tmp_print = tmp_print->next;
    }
    exit(0);
    return counter;
}

int check_command(char *line, char *command)
{
    int size_command = my_strlen(command);
    char *tmp = my_strstr(line, command);
    printf("%s\n", tmp);
    printf("%c\n", tmp[size_command]);
    if (tmp[size_command] == ' ' || tmp[size_command] == ',' || tmp[size_command] == '\0')
        return 1;
    return 0;
}

t_commands *find_commands(char *str)
{
    printf("LINE : %s\n", str);
    t_commands *command = NULL, *tmp = NULL; int nb_command = 0;
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strstr(str, op_tab[i].mnemonique) != NULL) 
            nb_command += check_command(str, op_tab[i].mnemonique);
    }
    if (nb_command == 0) return (NULL);
    if (nb_command == 1) {
        for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
            if (my_strstr(str, op_tab[i].mnemonique) != NULL) {
                command = create_command(&op_tab[i]);
                return (command);
            }
        }
    }
    static int fct_counter = 0;
    fct_counter++;
    t_counter *counter = NULL, *tmp_counter = NULL;
    printf("NB_COMMAND : %d\n", nb_command);
    for (int i = 0; i < nb_command; i++) {
        for (int j = 0, k = 0; op_tab[j].mnemonique != NULL; j++) {
            if (my_strstr(str, op_tab[j].mnemonique) != NULL && k >= i) {
                if (check_command(str, op_tab[j].mnemonique) == 1) {
                    tmp_counter = create_counter(op_tab[j].mnemonique,
                    my_strlen(my_strstr(str, op_tab[j].mnemonique)));
                    (counter == NULL) ? counter = tmp_counter :
                    push_back_counter(counter, tmp_counter);
                    k++; break;
                }
            }
            if (my_strstr(str, op_tab[j].mnemonique) != NULL && check_command(str, op_tab[j].mnemonique) == 1) k++;
        }
        printf("I : %d\n", i);
    }
    t_counter *tmp_print = counter;
    while (tmp_print != NULL) {
        printf("TURN1 : %d\n", fct_counter);
        printf("%s\n", tmp_print->command);
        printf("%d\n", tmp_print->sizeline);
        tmp_print = tmp_print->next;
    }
    counter = sort_counter(counter);
    tmp_print = counter;
    while (tmp_print != NULL) {
        printf("TURN : %d\n", fct_counter);
        printf("%s\n", tmp_print->command);
        printf("%d\n", tmp_print->sizeline);
        tmp_print = tmp_print->next;
    }
    // for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
    //     if (my_strstr(str, op_tab[i].mnemonique) != NULL) {
    //         tmp = create_command(&op_tab[i]);
    //         (command == NULL) ? command = tmp :
    //         push_back_commands(command, tmp);
    //     }
    // }
    // return command;
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
    exit(0);
    // WRITING
    write_file(core, fighter);
    // free(core);
    free_array(array);
    // CREATING THE .cor FILE
}
