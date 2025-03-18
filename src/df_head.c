/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_head
*/

#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int copy_column_info(dataframe_t *h, dataframe_t *df)
{
    h->column_names = malloc(sizeof(char *) * (h->nb_columns + 1));
    h->column_types = malloc(sizeof(column_type_t) * (h->nb_columns + 1));
    if (!h->column_names || !h->column_types)
        return 84;
    for (int i = 0; i < h->nb_columns; i++) {
        h->column_names[i] = strdup(df->column_names[i]);
        h->column_types[i] = df->column_types[i];
    }
    return (0);
}

static int copy_rows(dataframe_t *head, dataframe_t *df, int col, int nb)
{
    for (int j = 0; j < nb; j++) {
        if (df->column_types[col] == STRING)
            head->data[col][j] = strdup((char *)df->data[col][j]);
        else
            head->data[col][j] = df->data[j][col];
        if (!head->data[col][j])
            return (84);
    }
    return (0);
}

static int copy_data_values(dataframe_t *head, dataframe_t *df, int nb_rows)
{
    head->data = malloc(sizeof(void **) * (head->nb_rows + 1));
    if (!head->data)
        return (84);
    for (int i = 0; i < head->nb_rows; i++) {
        head->data[i] = malloc(sizeof(void *) * (head->nb_columns + 1));
        if (!head->data[i])
            return (84);
        if (copy_rows(head, df, i, nb_rows) == 84)
            return (84);
    }
    return (0);
}

dataframe_t *df_head(dataframe_t *df, int nb_rows)
{
    dataframe_t *head;

    if (nb_rows > df->nb_rows)
        return df;
    if (!df || nb_rows <= 0)
        return (NULL);
    if (nb_rows > df->nb_rows)
        nb_rows = df->nb_rows;
    head = malloc(sizeof(dataframe_t));
    if (!head)
        return (NULL);
    head->nb_rows = nb_rows;
    head->nb_columns = df->nb_columns;
    head->separator = strdup(df->separator);
    if (copy_column_info(head, df) == 84 ||
        copy_data_values(head, df, nb_rows) == 84)
        return (NULL);
    return (head);
}
