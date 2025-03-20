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
    return 0;
}

static int copy_rows(dataframe_t *head, dataframe_t *df, int row, int nb_cols)
{
    for (int col = 0; col < nb_cols; col++) {
        if (df->column_types[col] == STRING)
            head->data[row][col] = strdup((char *)df->data[row][col]);
        else
            head->data[row][col] = df->data[row][col];
        if (!head->data[row][col])
            return 84;
    }
    return 0;
}

static int copy_data_values(dataframe_t *head, dataframe_t *df, int nb_rows)
{
    head->data = malloc(sizeof(void **) * nb_rows);
    if (!head->data)
        return 84;
    for (int i = 0; i < nb_rows; i++) {
        head->data[i] = malloc(sizeof(void *) * head->nb_columns);
        if (!head->data[i])
            return 84;
        if (copy_rows(head, df, i, head->nb_columns) == 84)
            return 84;
    }
    return 0;
}

dataframe_t *df_head(dataframe_t *df, int nb_rows)
{
    dataframe_t *head;

    if (!df || nb_rows <= 0)
        return NULL;
    if (nb_rows > df->nb_rows)
        return df;
    head = malloc(sizeof(dataframe_t));
    if (!head)
        return NULL;
    head->nb_rows = nb_rows;
    head->nb_columns = df->nb_columns;
    head->separator = strdup(df->separator);
    if (!head->separator || copy_column_info(head, df) == 84 ||
        copy_data_values(head, df, nb_rows) == 84) {
        free(head);
        return NULL;
    }
    return head;
}
