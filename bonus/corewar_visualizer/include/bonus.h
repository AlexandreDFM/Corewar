/*
** EPITECH PROJECT, 2022
** BONUS_H_
** File description:
** Header file for bonus
*/

#include "my.h"
#include "ncurses.h"
#include "SFML/Audio.h"
#include "time.h"
#include "op.h"
#include "corewar.h"

#ifndef BONUS_H_
    #define BONUS_H_

typedef struct Vector3i {
    int x;
    int y;
    int z;
} vector3i;

typedef struct visu_core {
    int rows;
    int cols;
    char **array;
    sfMusic *pinguna;
    sfMusic *waitmusic;
    sfVector2i timer;
    clock_t clock1;
    clock_t clock2;
    int total_cycles;
    int cycles_before_die;
    char **champions_names;
    vector3i *champions_infos;
} t_visu_core;

char *hex_to_binary(char *hex);
unsigned char *open_file2(char *path, int size);

#endif /* !BONUS_H_ */
