/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

void algo_safe_check(toolbox *toolbox, int *ligne, int *nbrmatch)
{
    int count = 0;

    if (*nbrmatch > toolbox->nbrmaxstick)
        *nbrmatch = toolbox->nbrmaxstick;
    if (*nbrmatch <= 0)
        *nbrmatch = 1;
    if (*ligne == -1) {
        while (toolbox->tab[count] == 0)
            count++;
        *ligne = count;
    }
    if (toolbox->tab[*ligne] < *nbrmatch)
        *nbrmatch = toolbox->tab[*ligne];
}

void algo_win_2(toolbox *toolbox, int *ligne, int *nbrmatch, int pass[])
{
    int count = 0;

    if (pass[0] + pass[1] == toolbox->nbrcologne - 1
    && (toolbox->nbrtotal - *nbrmatch) % 2 == 0) {
        if (toolbox->nbrtotal - (*nbrmatch + 1) == 1
        && toolbox->tab[*ligne] >= (*nbrmatch + 1)) {
            *nbrmatch = *nbrmatch + 1;
        } else
            *nbrmatch = *nbrmatch - 1;
    }
    algo_win_2_1(toolbox, ligne, nbrmatch, pass);
}

void algo_win_1(toolbox *toolbox, int *ligne, int *nbrmatch, int *pass)
{
    int count = 0;
    int xor = pass[2];

    while (count < toolbox->nbrcologne) {
        if ((toolbox->tab[count] ^ xor) < toolbox->tab[count]
        && *nbrmatch != -1) {
            *ligne = count;
            *nbrmatch = toolbox->tab[count] - (toolbox->tab[count] ^ xor);
        }
        if (toolbox->tab[count] == 0 && count != toolbox->nbrcologne)
            pass[0]++;
        else if (toolbox->tab[count] == 1 && count != toolbox->nbrcologne)
            pass[1]++;
        count++;
    }
}

void algo_ai (int *ligne, int *nbrmatch, toolbox *toolbox)
{
    int count = 0;
    int xor = 0;
    int pass[] = {0, 0, 0};

    while (count < toolbox->nbrcologne) {
        xor = xor ^ toolbox->tab[count];
        count++;
    }
    if (xor != 0) {
        pass[2] = xor;
        algo_win_1(toolbox, ligne, nbrmatch, &pass[0]);
    }
    algo_win_2(toolbox, ligne, nbrmatch, pass);
    algo_safe_check(toolbox, ligne, nbrmatch);
}

toolbox *ai(toolbox *toolbox)
{
    int ligne = -1;
    int nbrmatch = 0;

    write(1, "\nAI's turn...\n", 14);
    algo_ai(&ligne, &nbrmatch, toolbox);
    toolbox->tab[ligne] = toolbox->tab[ligne] - nbrmatch;
    toolbox->nbrtotal = toolbox->nbrtotal - nbrmatch;
    write(1, "AI removed ", 11);
    my_put_nbr(nbrmatch);
    write(1, " match(es) from line ", 21);
    my_put_nbr(ligne + 1);
    write(1, "\n", 1);
    return (toolbox);
}