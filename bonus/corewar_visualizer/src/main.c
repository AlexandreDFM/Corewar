/*
** EPITECH PROJECT, 2022
** MAIN
** File description:
** Main function for the bonus
*/

#include "../include/bonus.h"

int main(int ac, char **av)
{
    (void) ac; (void) av;
    char *str = open_file("./interface/main_interface.txt", count_int_read("./interface/main_interface.txt"));
    int rows = get_rows(str);
    int cols = get_cols(str);
    char **array = my_strtwa(str, "\n");
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        for (int i = 0; array[i] != NULL; i++)
            mvwprintw(stdscr, LINES / 2 - rows / 2 + i, COLS / 2 - cols / 2 - 30, array[i]);
        refresh();
        if (getch() == 'q') break;
    }
    endwin();
    return (0);
}
