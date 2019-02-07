/*
** EPITECH PROJECT, 2019
** da
** File description:
** da
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

void algo_win_2_1(toolbox *toolbox, int *ligne, int *nbrmatch, int pass[])
{
    int count = 0;

    if (pass[0] + pass[1] == toolbox->nbrcologne || toolbox->nbrtotal == 1) {
        while (count < toolbox->nbrcologne) {
            if (toolbox->tab[count] == 1) {
                *ligne = count;
                *nbrmatch = 1;
                count = toolbox->nbrcologne;
            }
            count++;
        }
    }
}

int main(int ac, char **av)
{
    toolbox *toolbox;

    toolbox = check_recup_param(ac, av);
    if (toolbox == NULL)
        return (84);
    toolbox = prep(toolbox);
    print_game_board(toolbox);
    srand(time(NULL));
    return (jeu(toolbox));
}