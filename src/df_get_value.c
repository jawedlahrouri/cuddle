/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_value
*/

#include "my.h"
#include "dataframe.h"
#include <stdio.h>
#include <string.h>

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int col = 0;
    void *temps = NULL;

    while (strcmp(dataframe->column_names[col], column) != 0){
        col++;
    }
    temps = dataframe->data[col][row];
    return temps;
}
