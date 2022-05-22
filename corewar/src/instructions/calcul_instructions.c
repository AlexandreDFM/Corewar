/*
** EPITECH PROJECT, 2026
** B-CPE-201-NCE-2-1-corewar-corentin.levet
** File description:
** Created by leo,
*/

#include "../../include/corewar.h"

unsigned int pad_unsigned_int(unsigned int nbr, int size)
{
    return (nbr << BYTE * (size - 1));
}

int biggest_param(int size_param_1, int size_param_2)
{
    if (size_param_1 == size_param_2)
        return (0);
    else if (size_param_1 > size_param_2)
        return (1);
    else
        return (2);
}

unsigned int calcul_instruction(t_vector_2ui param, t_vector_2ui size,
    char operators)
{
    unsigned int res = 0;

    if (biggest_param(size.x, size.y) == 1)
        param.y = pad_unsigned_int(param.y, size.x);
    else if (biggest_param(size.x, size.y) == 2)
        param.x = pad_unsigned_int(param.x, size.y);

    (operators == '&') ? res = param.x & param.y :
    (operators == '|') ? res = param.x | param.y :
    (operators == '^') ? res = param.x ^ param.y : 0;

    return (res);
}