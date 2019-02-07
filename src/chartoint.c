/*
** EPITECH PROJECT, 2019
** chartoint
** File description:
** chartoint
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int chartoint(char *nb, char end)
{
    int result = 0;
    int size = my_strlen(nb, end);
    int a = 0;

    while (a <= (size-1)) {
        if (a == 0) {
            result = (nb[a] - 48) + result;
        } else {
            result = (nb[a] - 48) + result * 10;
        }
        a++;
    }
    return (result);
}