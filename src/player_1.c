/*
** EPITECH PROJECT, 2019
** player_1
** File description:
** player_1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int player_1(toolbox *toolbox, int *pass)
{
    char *str;
    int ligne = 0;

    write(1, "Line: ", 6);
    str = readouput(toolbox);
    if (str == NULL)
        return (-1);
    if (my_str_isnum(str, '\n') == 0
    || my_str_isnum(str, '\n') == 0 || str[0] == '\0') {
        write(1, "Error: invalid input (positive number expected)\n", 48);
    } else {
        ligne = chartoint(str, '\n');
        if (ligne <= 0 || ligne > toolbox->nbrcologne)
            write(1, "Error: this line is out of range\n", 33);
        else
            *pass = 2;
    }
    free(str);
    return (ligne);
}