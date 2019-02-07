/*
** EPITECH PROJECT, 2019
** print_game_board.c
** File description:
** print_game_board.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

void print_game_board_3(toolbox *toolbox, int i, int a, int b)
{
    while (i < (toolbox->largeur -
    (2 + (toolbox->largeur - (2 * (toolbox->nbrcologne - a))))) / 2) {
        write(1, " ", 1);
        i++;
    }
    b = 0;
    while (b < toolbox->tab[a]) {
        write(1, "|", 1);
        b++;
    }
    while (i + b < toolbox->largeur - 2) {
        write(1, " ", 1);
        i++;
    }
}

void print_game_board_2(toolbox *toolbox)
{
    int i = 0;
    int a = 0;
    int b = 0;

    while (a < toolbox->nbrcologne) {
        i = 0;
        write(1, "*" , 1);
        print_game_board_3(toolbox, i, a, b);
        write (1, "*\n", 2);
        a++;
    }
}

void print_game_board(toolbox *toolbox)
{
    int i = 0;

    while (i < toolbox->largeur) {
        write(1, "*" , 1);
        i++;
    }
    write(1, "\n", 1);
    print_game_board_2(toolbox);
    i = 0;
    while (i < toolbox->largeur) {
        write(1, "*" , 1);
        i++;
    }
    write(1, "\n", 1);
}
