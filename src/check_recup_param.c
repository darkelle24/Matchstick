/*
** EPITECH PROJECT, 2019
** check_recup_param
** File description:
** check_recup_param
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

toolbox *check_recup_param(int ac, char **av)
{
    toolbox *toolbox = malloc(sizeof(toolbox));

    if (my_str_isnum(av[1], '\0') == 0 || my_str_isnum(av[2], '\0') == 0)
        return (NULL);
    toolbox->nbrcologne = chartoint(av[1], '\0');
    toolbox->nbrmaxstick = chartoint(av[2], '\0');
    if (toolbox->nbrcologne <= 1 || toolbox->nbrcologne >= 100
    || toolbox->nbrmaxstick <= 0)
        return (NULL);
    return (toolbox);
}