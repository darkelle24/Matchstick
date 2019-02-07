/*
** EPITECH PROJECT, 2019
** player_2
** File description:
** player_2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int player_2_3(toolbox *toolbox, int pass, int matches)
{
    if (matches <= 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        pass = 0;
    } else if (matches > toolbox->nbrmaxstick) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(toolbox->nbrmaxstick);
        write(1, " matches per turn\n", 18);
        pass = 0;
    } else
        pass = 3;
    return (pass);
}

int player_2_2(toolbox *toolbox, char *str, int *pass, int ligne)
{
    int matches = 0;

    if (my_str_isnum(str, '\n') == 0
    || my_str_isnum(str, '\n') == 0 || str[0] == '\0') {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        *pass = 0;
    } else {
        matches = chartoint(str, '\n');
        if (matches > toolbox->tab[ligne - 1]) {
            write(1, "Error: not enough matches on this line\n", 39);
            *pass = 0;
        } else
            *pass = player_2_3(toolbox, *pass, matches);
    }
    return (matches);
}

int player_2(toolbox *toolbox, int ligne, int *pass)
{
    char *str;
    int matches = 0;

    write(1, "Matches: ", 9);
    str = readouput(toolbox);
    if (str == NULL)
        return (-1);
    matches = player_2_2(toolbox, str, pass, ligne);
    free(str);
    return (matches);
}