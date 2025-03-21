/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_sort
*/

#include "dataframe.h"
#include <stdlib.h>
#include <string.h>

static int initialize_df_structure(dataframe_t *new_df, dataframe_t *df,
    int col_idx)
{
    new_df->nb_rows = df->nb_rows;
    new_df->nb_columns = df->nb_columns;
    new_df->column_names = df->column_names;
    new_df->column_types = df->column_types;
    new_df->separator = strdup(df->separator);
    if (!new_df->separator) {
        free(new_df);
        return -1;
    }
    return 0;
}

static void copy_filtered_data(dataframe_t *new_df, dataframe_t *df,
    int col_idx, bool (*filter_func)(void *, void *))
{
    int new_row = 0;

    for (int i = 0; i < df->nb_rows; i++) {
        if (sort_func(df->data[i][col_idx], df->data[i + 1][col_idx]) == 1) {
            swap_row(new_df, df, new_row, i);
            new_row++;
        }
    }
}

dataframe_t *df_sort(dataframe_t *df, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    int col_idx = get_column_index(df, column);
    dataframe_t *new_df = malloc(sizeof(dataframe_t));

    if (!new_df || col_idx == -1)
        return NULL;
    if (initialize_df_structure(new_df, df, col_idx) == -1)
        return NULL;
        new_df->data = malloc(sizeof(void *) * new_df->nb_rows);
    for (int i = 0; i < new_df->nb_rows; i++)
        new_df->data[i] = malloc(sizeof(void *) * new_df->nb_columns);
    copy_sort_data(new_df, df, col_idx, sort_func);
    return new_df;
}
