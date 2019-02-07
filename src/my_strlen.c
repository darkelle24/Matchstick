/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int my_strlen(char const *str, char end)
{
    int nbchar;

    nbchar = 0;
    while (*str != end) {
        nbchar++;
        str++;
    }
    return (nbchar);
}