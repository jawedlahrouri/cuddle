/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_apply
*/

#include "dataframe.h"

void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));

    *new_value = *(int *)value * 2;
    return new_value;
}

dataframe_t *df_apply(dataframe_t *dataframe,
    const char *column, void *(*apply_func)(void *value))
{
    int col = -1;
    int *new_value = 0;

    for (int j = 0; dataframe->column_names[j]; j++) {
        if (strcmp(column, dataframe->column_names[j]) == 0) {
            col = j;
            break;
        }
    }
    if (col == -1)
        return dataframe;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        new_value = apply_func(&(int){atoi(dataframe->data[i][col])});
        if (new_value) {
            sprintf(dataframe->data[i][col], "%d", *new_value);
            free(new_value);
        }
    }
    return dataframe;
}
