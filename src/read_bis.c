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
    return (c >= '0' && c <= '9') || c == '.';
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

int check_error(char ***arg, int i, int j, int *is_float)
{
    for (int a = 0; arg[j][i][a]; a++) {
        if (!is_valid_digit(arg[j][i][a]))
            return 0;
        if (arg[j][i][a] == '.')
            *is_float = 1;
    }
    return 1;
}

int is_num(char ***arg, int nb_row, int i)
{
    int point = 0;
    int is_float = 0;

    for (int j = 0; j < nb_row; j++) {
        if (is_negative(arg[j][i]))
            return 2;
        point = count_points(arg[j][i]);
        if (point > 1)
            return 84;
        if (check_error(arg, i, j, &is_float) == 0)
            return 0;
    }
    return is_float ? 3 : 1;
}
