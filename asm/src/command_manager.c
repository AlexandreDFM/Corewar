/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** command_manager
*/

#include "../include/asm.h"

t_counter *sort_counter(t_counter *counter)
{
    t_counter *tmp = counter;
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->sizeline < tmp->next->sizeline) {
            swapnodes(&counter, tmp->sizeline, tmp->next->sizeline);
        }
        tmp = tmp->next;
    }
    return counter;
}

int check_command(char *line, char *command)
{
    int size_command = my_strlen(command);
    char *tmp = my_strstr(line, command);
    if (tmp[size_command] == ' ' || tmp[size_command] == ','
    || tmp[size_command] == '\0' || tmp[size_command] == ':')
        return 1;
    return 0;
}

t_commands *find_commands(char *str)
{
    printf("LINE : %s\n", str);
    t_commands *command = NULL; int nb_command = 0;
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
    t_counter *counter = NULL, *tmp_counter = NULL;
    for (int i = 0; i < nb_command; i++) {
        for (int j = 0, k = 0; op_tab[j].mnemonique != NULL; j++) {
            if (my_strstr(str, op_tab[j].mnemonique) != NULL && k >= i) {
                if (check_command(str, op_tab[j].mnemonique) == 1) {
                    tmp_counter = create_counter(&op_tab[j],
                    my_strlen(my_strstr(str, op_tab[j].mnemonique)));
                    (counter == NULL) ? counter = tmp_counter :
                    push_back_counter(counter, tmp_counter);
                    k++; break;
                }
            }
            if (my_strstr(str, op_tab[j].mnemonique) != NULL && check_command(str, op_tab[j].mnemonique) == 1) k++;
        }
    }
    counter = sort_counter(counter);
    for (t_counter *tmp = counter; tmp != NULL; tmp = tmp->next) {
        printf("(╯°□°)╯︵ ┻━┻ MNEMONIQUETAMERE : %s\n", tmp->command->mnemonique);
    }
    for (t_counter *tmp = counter; tmp != NULL; tmp = tmp->next) {
        if (command == NULL) command = create_command(tmp->command);
        else push_back_commands(command, create_command(tmp->command));
    }
    return command;
}
