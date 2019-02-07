/*
** EPITECH PROJECT, 2019
** jeu
** File description:
** jeu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int jeu(toolbox *toolbox)
{
    int win = 0;

    while (win == 0) {
        toolbox = player(toolbox);
        if (toolbox == NULL)
            return (0);
        print_game_board(toolbox);
        if (toolbox->nbrtotal == 0)
            win = 2;
        else {
            toolbox = ai(toolbox);
            print_game_board(toolbox);
            if (toolbox->nbrtotal == 0)
                win = 1;
        }
    }
    write_win(win);
    return (win);
}