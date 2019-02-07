/*
** EPITECH PROJECT, 2019
** readoutput
** File description:
** readoutput
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

char *readouput(toolbox *toolbox)
{
    char *str = NULL;
    size_t len = 0;
    int test = getline(&str, &len, stdin);

    if (test == -1)
        return (NULL);
    return (str);
}