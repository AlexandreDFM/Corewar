/*
** EPITECH PROJECT, 2022
** COREWAR_H_
** File description:
** Header file for corewar
*/

#include "proto.h"
#include "op.h"

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
    " By default, the first\n\t\t\t\tfree number in the parameter order\n"
    #define LOAD_ADRESS "\t-a load_address\t\tsets the next program's loading"\
    " adress. When no address\n\t\t\t\tis specified, optimize the addresses"\
    " so that the processes\n\t\t\t\tare as far away from each other as"\
    " possible. The addresses\n\t\t\t\tare MEM_SIZE modulo.\n"
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40
    #define DUMP    "-dump"
    #define PROG_NB "-n"
    #define ADDRESS "-a"
    #define MAX_PLAYER 4
    #define BIT 1
    #define BYTE 8
    #define NB_PLAYER 0
    #define INDEX 1
    #define CYCLE_TMP 2
    #define LEN_INSTRUCT 3
    #define NB_LIVE 4

typedef struct Vector_2i_s {
    int x;
    int y;
} t_vector_2i;

typedef struct Vector_2ui_s {
    unsigned int x;
    unsigned int y;
} t_vector_2ui;

typedef struct list_champions_s {
    unsigned int address;
    unsigned char *file;
    unsigned char *name;
    unsigned char *comment;
    unsigned char *command;
    int prog_size;
    int reg[REG_NUMBER];
    int infos[5];
    struct list_champions_s *next;
    struct list_champions_s *prev;
} t_list_champions;

typedef struct arena_s {
    unsigned char tab[MEM_SIZE];
    unsigned int nbr_prog;
    unsigned int cycle;
    unsigned int cycle_to_die;
    unsigned int cycle_last_check;
} t_arena;

typedef struct corewar_s {
    t_list_champions *champions;
    t_arena *arena;
    unsigned int load_address[4];
    unsigned int progs_nb[4];
} t_corewar;

int read_champions(t_corewar *corewar, char **av);
void parse_flags(t_corewar *corewar, char **av);
void parse_name_champion(t_list_champions *champion);
void parse_prog_size(t_list_champions *champions);
void parse_comment(t_list_champions *champions);
void parse_command(t_list_champions *champions);
void if_magic(t_list_champions *champions);
void free_corewar(t_corewar *corewar);
void free_champions(t_list_champions *champions);
t_arena *init_vm(void);
void launch_vm(t_corewar *corewar);
unsigned int hex_to_uint(unsigned char *tab, int index_byte,
    int size_instruction);
void push_back_new_champ(t_list_champions **list, t_list_champions *champion,
    int new_address, unsigned char *tab);

void live_instruction(t_corewar *corewar, t_list_champions *champions);
void ld_instruction(t_corewar *corewar, t_list_champions *champions);
void st_instruction(t_corewar *corewar, t_list_champions *champions);
void add_instruction(t_corewar *corewar, t_list_champions *champions);
void sub_instruction(t_corewar *corewar, t_list_champions *champions);
void and_instruction(t_corewar *corewar, t_list_champions *champions);
void or_instruction(t_corewar *corewar, t_list_champions *champions);
void xor_instruction(t_corewar *corewar, t_list_champions *champions);
void zjmp_instruction(t_corewar *corewar, t_list_champions *champions);
void ldi_instruction(t_corewar *corewar, t_list_champions *champions);
void sti_instruction(t_corewar *corewar, t_list_champions *champions);
void fork_instruction(t_corewar *corewar, t_list_champions *champions);
void lld_instruction(t_corewar *corewar, t_list_champions *champions);
void lldi_instruction(t_corewar *corewar, t_list_champions *champions);
void lfork_instruction(t_corewar *corewar, t_list_champions *champions);
void aff_instruction(t_corewar *corewar, t_list_champions *champions);
unsigned int do_op_from_pcb(t_corewar *corewar, char *pcb, char op, int index);
int get_len_instruct_from_pcb(char *pcb, int size_direct);
unsigned int calcul_instruction(t_vector_2ui param, t_vector_2ui size,
    char operators);
unsigned int pad_unsigned_int(unsigned int nbr, int size);
unsigned int ld_get_distance(t_corewar *corewar,
    t_list_champions *champions, char *pcb, int size_direct);

#endif
