/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

unsigned int stock_multiple_bytes_in_one_int(unsigned char *bytes, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += (bytes[i] >> BYTE * i);
        printf("byte = %x\n", bytes[i]);
        printf("res = %x\n", res);
    }
    return res;
}

int get_len_instruct_from_pcb(char *pcb, int size_direct)
{
    char *tmp = malloc(sizeof(char) * my_strlen(pcb) + 1);
    my_memset(tmp, '\0', my_strlen(pcb));
    tmp = my_strcpy(tmp, pcb);
    int len = 0;
    while (tmp[0] != '\0') {
        my_strncmp(tmp, "01", 2) == 0 ? len += 1 : 0;
        my_strncmp(tmp, "11", 2) == 0 ? len += 2 : 0;
        my_strncmp(tmp, "10", 2) == 0 ? len += size_direct : 0;
        tmp += 2;
    }
    return len;
}

t_vector_2ui set_param_for_op(unsigned char *tab, char *pcb, t_vector_2ui size,
    int index)
{
    unsigned char to_pass[4]; t_vector_2ui param = {0, 0};
    if (my_strncmp(pcb, "01", 2) == 0) {
        size.x == 0 ? size.x = 1 :
        size.y == 0 ? size.y = 1 : 0;
        param.x = tab[9 + size.x + size.y];
    }
    if (my_strncmp(pcb, "11", 2) == 0) {
        size.x == 0 ? size.x = 4 :
        size.y == 0 ? size.y = 4 : 0;
        for (int i = 0; i < 4; i++) to_pass[i] = tab[index + i + 2];
        param.x = stock_multiple_bytes_in_one_int(to_pass, size.x);
    }
    if (my_strncmp(pcb, "10", 2) == 0) {
        size.x == 0 ? size.x = 2 :
        size.y == 0 ? size.y = 2 : 0;
        for (int i = 0; i < 2; i++) to_pass[i] = tab[index + i + 2];
        param.x = stock_multiple_bytes_in_one_int(to_pass, size.x);
    }
    size.y == 0 ? param.y = size.x : size.y; return (param);
}

unsigned int do_op_from_pcb(t_corewar *corewar, char *pcb, char o, int index)
{
    t_vector_2ui param_1 = {0, 0}, param_2 = {0, 0}, size = {0, 0};
    param_1 = set_param_for_op(corewar->arena->tab, pcb, size, index);
    size.x = param_1.y;
    pcb += 2;
    param_2 = set_param_for_op(corewar->arena->tab, pcb, size, index);
    size.y = param_2.y;
    pcb += 2;
    return (calcul_instruction((t_vector_2ui){param_1.x, param_2.x}, size, o));
}
