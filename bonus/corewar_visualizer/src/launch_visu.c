/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for the bonus
*/

#include "../include/bonus.h"

void my_print_timer(int rows, int cols, sfVector2i timer)
{
    int lines_calc = LINES / 2 - rows / 2 + 32;
    int cols_calc = COLS / 2 - cols / 2 - 30 + 170;
    if (timer.x < 10) {
        if (timer.y < 10) {
            mvwprintw(stdscr, lines_calc, cols_calc, "0%d : 0%d",timer.y, timer.x);
        } else {
            mvwprintw(stdscr, lines_calc, cols_calc, "%d : 0%d",timer.y, timer.x);
        }
    } else {
        if (timer.y < 10) {
            mvwprintw(stdscr, lines_calc, cols_calc, "0%d : %d",timer.y, timer.x);
        } else {
            mvwprintw(stdscr, lines_calc, cols_calc, "%d : %d",timer.y, timer.x);
        }
    }
}

void my_print_champ(sfVector2i coords, unsigned char *namechamp, vector3i infos)
{
    mvwprintw(stdscr, coords.x, coords.y + 132, "%.14s", namechamp);
    mvwprintw(stdscr, coords.x, coords.y + 147, "%d", infos.x);
    mvwprintw(stdscr, coords.x, coords.y + 159, "%d", infos.y);
    mvwprintw(stdscr, coords.x, coords.y + 170, infos.z == 1 ? "    YES" : "    NO");
}

void my_interface(t_corewar *corewar, t_visu_core *core, sfVector2i timer)
{
    int rows = LINES / 2 - core->rows / 2, cols = COLS / 2 - core->cols / 2 - 30;
    for (int i = 0; core->array[i] != NULL; i++) {
        for (int j = 0; core->array[i][j] != '\0'; j++) {
            if (core->array[i][j] == '1') {
                attron(COLOR_PAIR(1));
                mvwprintw(stdscr, rows + i, cols + j, " ");
                attroff(COLOR_PAIR(1));
            } else if (core->array[i][j] == '*') {
                attron(COLOR_PAIR(2));
                mvwprintw(stdscr, rows + i, cols + j, " ");
                attroff(COLOR_PAIR(2));
            } else {
                mvwprintw(stdscr, rows + i, cols + j, "%c", core->array[i][j]);
            }
        }
    }
    for (int j = 0, lines2 = 2, cols2 = 0; j < 6144; j++, cols2++) {
        if (j % 128 == 0) lines2 += 1, cols2 = 0;
        attron(COLOR_PAIR(3));
        mvwprintw(stdscr, lines2, cols + cols2, " ");
        mvwprintw(stdscr, lines2, cols + cols2, "%x", corewar->arena->tab[j]);
        attroff(COLOR_PAIR(3));
    }
    for (int j = 0, lines2 = 2, cols2 = 0; j < 6144; j++, cols2++) {
        if (j % 128 == 0) lines2 += 1, cols2 = 0;
        for (t_list_champions *champ = corewar->champions; champ != NULL; champ = champ->next) {
            if (champ->infos[1] == j) {
                int size = sizeof(champ->command) * 4;
                mvwprintw(stdscr, 0, 0, "%d", size);
                attron(COLOR_PAIR(5));
                for (int u = 0; u < size; u++) {
                    mvwprintw(stdscr, lines2, cols + cols2 + u, "c");
                }
                attroff(COLOR_PAIR(5));
                attron(COLOR_PAIR(4));
                mvwprintw(stdscr, 0 + lines2, cols + cols2, " ");
                attroff(COLOR_PAIR(4));
            }
        }
    }
    mvwprintw(stdscr, rows + 6, cols + 163, "\t%lu", corewar->arena->cycle);
    mvwprintw(stdscr, rows + 7, cols + 163, "\t%lu", corewar->arena->cycle_to_die);
    t_list_champions *champ = corewar->champions;
    for (int i = 15, j = 0; champ != NULL; champ = champ->next, i += 2, j++) {
        // my_print_champ((sfVector2i) {rows + i, cols}, champ->name, (vector3i) {champ->number, champ->last_live, champ->alive});
        core->champions_infos[j] = (vector3i) {champ->infos[4], core->champions_infos[j].y, core->champions_infos[j].y};
        my_print_champ((sfVector2i) {rows + i, cols}, champ->name, core->champions_infos[j]);
    }
    my_print_timer(core->rows, core->cols, timer);
}

void time_gestionnary(t_corewar *corewar, int i, clock_t *clock1, clock_t *clock2, sfVector2i *timer)
{
    *clock2 = clock();
    if (i == 1 && corewar->winner == 0) {
        pos_player(corewar);
        if (corewar->arena->cycle_last_check == corewar->arena->cycle_to_die) {
            corewar->arena->cycle_last_check = 0;
            detect_death(corewar);
            set_nb_alive_to_zero(corewar);
            corewar->one_death == 0 ?
                corewar->arena->cycle_to_die -= CYCLE_DELTA : 0;
        }
        check_champions(corewar);
        corewar->arena->cycle_last_check++, corewar->arena->cycle++;
    }
    if (((*clock2) - (*clock1)) / CLOCKS_PER_SEC > 1 ) {
        clear();
        refresh();
        *clock1 = clock();
        (*timer).x += 1;
        if ((*timer).x > 59) {
            (*timer).x = 0;
            (*timer).y += 1;
        }
    }
}

void music_gestionnary(sfMusic *music1, sfMusic *music2)
{
    if (sfMusic_getStatus(music1) != sfPlaying) {
        sfMusic_stop(music2); sfMusic_play(music1);
    }
}

sfMusic *setup_music(char *pathmusic)
{
    sfMusic *music = sfMusic_createFromFile(pathmusic);
    sfMusic_setLoop(music, sfTrue); sfMusic_setVolume(music, 50);
    sfMusic_setPitch(music, 1.5);
    return (music);
}

t_visu_core init_visu_core(char *filename)
{
    t_visu_core visu_core;
    char *str = open_file(filename, count_int_read(filename));
    visu_core.array = my_strtwa(str, "\n");
    visu_core.rows = get_rows(str);
    visu_core.cols = get_cols(str);
    visu_core.timer = (sfVector2i) {0, 0};
    visu_core.clock1 = clock();
    visu_core.clock2 = clock();
    visu_core.pinguna = setup_music("./music/pingana.ogg");
    visu_core.waitmusic = setup_music("./music/wait_music.ogg");
    visu_core.clock1 = clock(); visu_core.clock2 = clock();
    visu_core.total_cycles = 0;
    visu_core.cycles_before_die = 0;
    free(str);
    return (visu_core);
}

void fill_visu_core(t_visu_core *core)
{
    core->champions_names = malloc(sizeof(char *) * 4);
    core->champions_infos = malloc(sizeof(vector3i) * 4);
    core->champions_names[0] = strdup("CHAMPION 1");
    core->champions_names[1] = strdup("CHAMPION 2");
    core->champions_names[2] = strdup("CHAMPION 3");
    core->champions_names[3] = strdup("CHAMPION 4");
    core->champions_infos[0] = (vector3i) {0, 0, 0};
    core->champions_infos[1] = (vector3i) {0, 0, 0};
    core->champions_infos[2] = (vector3i) {0, 0, 0};
    core->champions_infos[3] = (vector3i) {0, 0, 0};
}

void free_visu_core(t_visu_core *visu_core)
{
    for (int i = 0; visu_core->array[i] != NULL; i++)
        free(visu_core->array[i]);
    free(visu_core->array);
    sfMusic_destroy(visu_core->pinguna);
    sfMusic_destroy(visu_core->waitmusic);
}

int launch_visu(t_corewar *corewar)
{
    t_visu_core core = init_visu_core("./interface/main_interface.txt");
    fill_visu_core(&core);
    initscr(); noecho(); curs_set(0);
    keypad(stdscr, TRUE); nodelay(stdscr, TRUE); start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_CYAN);
    int pause = 1, input = 0;
    sfVector2i timer = {0, 0}; sfVector2i trash = {0, 0};
    while (1) {
        if (COLS / 2 - core.cols / 2 - 30 < 0 || LINES / 2 - core.rows / 2 < 0) {
            clear();
            mvwprintw(stdscr, LINES / 2, COLS / 2 - (20 / 2), "Wrong Terminal size");
            refresh();
        } else if (pause == 1) {
            music_gestionnary(core.waitmusic, core.pinguna);
            time_gestionnary(corewar, 0, &core.clock1, &core.clock2, &trash);
            my_interface(corewar, &core, timer);
        } else {
            music_gestionnary(core.pinguna, core.waitmusic);
            time_gestionnary(corewar, 1, &core.clock1, &core.clock2, &timer);
            my_interface(corewar, &core, timer);
        }
        input = getch();
        if (input == 'q') break;
        else if (input == ' ') pause = pause == 1 ? 0 : 1;
    }
    endwin(); free_visu_core(&core); return (0);
}
