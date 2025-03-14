/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_tail
*/

#include "dataframe.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int copy_column_info(dataframe_t *tail, dataframe_t *df)
{
    int nb_col = tail->nb_columns;

    tail->column_names = malloc(sizeof(char *) * (tail->nb_columns + 1));
    tail->column_types = malloc(sizeof(column_type_t) * (nb_col + 1));
    if (!tail->column_names || !tail->column_types)
        return 84;
    for (int i = 0; i < tail->nb_columns; i++) {
        tail->column_names[i] = strdup(df->column_names[i]);
        tail->column_types[i] = df->column_types[i];
    }
    return (0);
}

static int copy_row(dataframe_t *tail, dataframe_t *df, int row, int start)
{
    tail->data[row] = malloc(sizeof(void *) * (tail->nb_columns + 1));
    if (!tail->data[row])
        return (84);
    for (int j = 0; j < tail->nb_columns; j++) {
        if (df->column_types[j] == STRING)
            tail->data[row][j] = strdup((char *)df->data[start + row][j]);
        else
            tail->data[row][j] = df->data[start + row][j];
        if (!tail->data[row][j])
            return (84);
    }
    return (0);
}

static int copy_data_values(dataframe_t *tail, dataframe_t *df, int start)
{
    tail->data = malloc(sizeof(void **) * (tail->nb_rows + 1));
    if (!tail->data)
        return (84);
    for (int i = 0; i < tail->nb_rows; i++) {
        if (copy_row(tail, df, i, start) == 84)
            return (84);
    }
    return (0);
}

dataframe_t *df_tail(dataframe_t *df, int nb_rows)
{
    dataframe_t *tail;
    int start_index;

    if (!df || nb_rows <= 0)
        return (NULL);
    if (nb_rows > df->nb_rows)
        nb_rows = df->nb_rows;
    start_index = df->nb_rows - nb_rows;
    tail = malloc(sizeof(dataframe_t));
    if (!tail)
        return (NULL);
    tail->nb_rows = nb_rows;
    tail->nb_columns = df->nb_columns;
    tail->separator = strdup(df->separator);
    if (copy_column_info(tail, df) == 84 ||
        copy_data_values(tail, df, start_index) == 84)
        return (NULL);
    return (tail);
}
