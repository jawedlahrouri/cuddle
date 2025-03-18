/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_filter
*/

#include "my.h"

/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_filter
*/

#include "dataframe.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int get_column_index(dataframe_t *df, const char *column)
{
    for (int i = 0; i < df->nb_columns; i++) {
        if (strcmp(df->column_names[i], column) == 0)
            return i;
    }
    return -1;
}

static int count_matching_rows(dataframe_t *df, int col_idx,
    bool (*filter_func)(void *))
{
    int count = 0;

    for (int i = 0; i < df->nb_rows; i++) {
        if (filter_func(df->data[col_idx][i]))
            count++;
    }
    return count;
}

static void copy_row(dataframe_t *new_df, dataframe_t *df, int new_row, int old_row)
{
    for (int j = 0; j < df->nb_columns; j++) {
        if (df->column_types[j] == STRING)
            new_df->data[j][new_row] = strdup((char *)df->data[j][old_row]);
        else
            new_df->data[j][new_row] = df->data[j][old_row];
    }
}

static void copy_filtered_data(dataframe_t *new_df, dataframe_t *df,
    int col_idx, bool (*filter_func)(void *))
{
    int new_row = 0;

    for (int i = 0; i < df->nb_columns; i++)
        new_df->data[i] = malloc(sizeof(void *) * new_df->nb_rows);
    for (int i = 0; i < df->nb_rows; i++) {
        if (!filter_func(df->data[col_idx][i]))
            continue;
        copy_row(new_df, df, new_row, i);
        new_row++;
    }
}

dataframe_t *df_filter(dataframe_t *df, const char *column,
    bool (*filter_func)(void *value))
{
    int col_idx;
    dataframe_t *new_df = malloc(sizeof(dataframe_t));

    if (!df || !column || !filter_func || !new_df)
        return NULL;
    col_idx = get_column_index(df, column);
    if (col_idx == -1)
        return NULL;
    new_df->nb_rows = count_matching_rows(df, col_idx, filter_func);
    new_df->nb_columns = df->nb_columns;
    new_df->column_names = df->column_names;
    new_df->column_types = df->column_types;
    new_df->data = malloc(sizeof(void **) * new_df->nb_columns);
    new_df->separator = strdup(df->separator);
    if (!new_df->data)
        return NULL;
    copy_filtered_data(new_df, df, col_idx, filter_func);
    return new_df;
}

bool filter_func(void *value)
{
    return (*(int *)value > 30);
}
