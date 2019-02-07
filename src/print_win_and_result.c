/*
** EPITECH PROJECT, 2019
** print
** File description:
** print
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

void write_win(int win)
{
    if (win == 2)
        write(1, "You lost, too bad...\n", 21);
    else
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
}

void print_result(int ligne, int nbrmatch)
{
    write(1, "Player removed ", 15);
    my_put_nbr(nbrmatch);
    write(1, " match(es) from line ", 21);
    my_put_nbr(ligne);
    write(1, "\n", 1);
}