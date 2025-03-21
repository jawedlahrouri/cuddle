/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** read_bis
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int is_negative(char *str)
{
    return str[0] == '-';
}

int is_valid_digit(char c)
{
    return (c >= '0' && c <= '9') ||
        c == '.' || c == '-';
}

int count_points(char *str)
{
    int point = 0;

    for (int a = 0; str[a]; a++) {
        if (str[a] == '.')
            point++;
    }
    return point;
}

int check_error(char ***arg, int i, int j)
{
    for (int a = 0; arg[j][i][a]; a++) {
        if (!is_valid_digit(arg[j][i][a]))
            return 0;
        if (arg[j][i][a] == '.')
            return 1;
    }
    return 2;
}

int is_num(char ***arg, int i)
{
    int point = 0;
    int is_float = check_error(arg, i, 0);

    point = count_points(arg[0][i]);
    if (point > 1)
        return 84;
    if (is_float == 0)
        return 0;
    if (is_float == 1)
        return 3;
    if (is_negative(arg[0][i]))
        return 1;
    return 2;
}
