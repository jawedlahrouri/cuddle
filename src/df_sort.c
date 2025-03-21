/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_sort
*/

#include "dataframe.h"
#include <stdlib.h>
#include <string.h>

void swap_row(void ***row1, void ***row2)
{
    void **temp = *row1;

    *row1 = *row2;
    *row2 = temp;
}

void loop_swap(dataframe_t *df, int col_idx, int i,
    bool (*sort_func)(void *, void *))
{
    for (int j = 0; j < df->nb_rows - i - 1; j++) {
        if (sort_func(df->data[j][col_idx], df->data[j + 1][col_idx])) {
            swap_row(&df->data[j], &df->data[j + 1]);
        }
    }
}

dataframe_t *df_sort(dataframe_t *df, const char *column,
    bool (*sort_func)(void *, void *))
{
    int col_idx = get_column_index(df, column);

    if (col_idx == -1)
        return NULL;
    for (int i = 0; i < df->nb_rows - 1; i++)
        loop_swap(df, col_idx, i, sort_func);
    return df;
}
