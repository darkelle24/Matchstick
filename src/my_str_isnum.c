/*
** EPITECH PROJECT, 2019
** my_str_is_num
** File description:
** my_str_isnum
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/my.h"

int my_str_isnum(char const *str, char end)
{
    while (*str != end) {
        if (*str < 48 || *str > 57) {
            return (0);
        }
        str++;
    }
    return (1);
}