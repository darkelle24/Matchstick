/*
** EPITECH PROJECT, 2019
** player
** File description:
** player
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

toolbox *player(toolbox *toolbox)
{
    int ligne = 0;
    int nbrmatch = 0;
    int pass = 0;

    write(1, "\nYour turn:\n", 12);
    while (pass != 3) {
        ligne = player_1(toolbox, &pass);
        if (pass == 2)
            nbrmatch = player_2(toolbox, ligne, &pass);
        if (ligne == -1 || nbrmatch == -1)
            return (NULL);
    }
    toolbox->tab[ligne - 1] = toolbox->tab[ligne - 1] - nbrmatch;
    toolbox->nbrtotal = toolbox->nbrtotal - nbrmatch;
    print_result(ligne, nbrmatch);
    return (toolbox);
}