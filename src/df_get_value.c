/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_value
*/

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
    temps = dataframe->data[row][col];
    return temps;
}

int find_col(dataframe_t *dataframe, const char *column)
{
    int col = 0;

    while (dataframe->column_names[col] != NULL) {
        if (strcmp(dataframe->column_names[col], column) == 0)
            break;
        col++;
    }
    return col;
}

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    int col = 0;
    void **temps = NULL;

    if (!dataframe || !dataframe->column_names || !dataframe->data)
        return NULL;
    col = find_col(dataframe, column);
    if (dataframe->column_names[col] == NULL)
        return NULL;
    temps = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (!temps)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        if (dataframe->data[i][col] == NULL)
            temps[i] = NULL;
        else
            temps[i] = strdup((char *)dataframe->data[i][col]);
    }
    temps[dataframe->nb_rows] = NULL;
    return temps;
}

int is_inlist(void **temps, void *verif, int nbr)
{
    if (!temps || !verif)
        return 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(temps[i], verif) == 0)
            return 1;
    }
    return 0;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    int col = 0;
    void **temps = NULL;
    int a = 0;

    if (!dataframe || !dataframe->column_names || !dataframe->data)
        return NULL;
    col = find_col(dataframe, column);
    if (dataframe->column_names[col] == NULL)
        return NULL;
    temps = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (!temps)
        return NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        if (is_inlist(temps, dataframe->data[i][col], a) == 0){
            temps[a] = strdup((char *)dataframe->data[i][col]);
            a++;
        }
    }
    temps[a] = NULL;
    return temps;
}
