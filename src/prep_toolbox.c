/*
** EPITECH PROJECT, 2019
** prep
** File description:
** prep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

toolbox *prep(toolbox *toolbox)
{
    int count = 1;

    toolbox->nbrtotal = toolbox->nbrcologne * toolbox->nbrcologne;
    toolbox->tab = malloc(sizeof(int) * toolbox->nbrcologne);
    toolbox->tab[0] = 1;
    while (count < toolbox->nbrcologne) {
        toolbox->tab[count] = toolbox->tab[count - 1] + 2;
        count++;
    }
    toolbox->largeur = toolbox->tab[toolbox->nbrcologne - 1] + 2;
    return (toolbox);
}