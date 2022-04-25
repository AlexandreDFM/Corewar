/*
** EPITECH PROJECT, 2022
** COREWAR_H_
** File description:
** Header file for corewar
*/

#include "my.h"

#ifndef COREWAR_H_
    #define COREWAR_H_

#endif /* COREWAR_H_ */

#ifndef USAGE_H_
    #define USAGE_H_

    #define NBR_CYCLE "\t-dump nbr_cycle\t\tdumps the memory after the"\
    " nbr_cycle execution (if the\n\t\t\t\tround isn't already over) with "\
    "the following format:\n\t\t\t\t32 bytes/line in hexadecimal"\
    " (A0BCDEFE1DD3...)\n"

    #define PROG_NUMBER "\t-n prog_number\t\tsets the next program's number."\
    "By default, the first\n\t\t\t\tfree number in the parameter order\n"

    #define LOAD_ADRESS "\t-a load_address\t\tsets the next program's loading"\
    " adress. When no address\n\t\t\t\tis specified, optimize the addresses"\
    " so that the processes\n\t\t\t\tare as far away from each other as"\
    " possible. The addresses\n\t\t\t\tare MEM_SIZE modulo.\n"

#endif
