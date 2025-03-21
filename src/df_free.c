/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_free
*/

#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>

void df_free(dataframe_t *data)
{
    if (!data)
        return;
    if (data->column_names){
        for (int i = 0; i < data->nb_columns; i++)
            free(data->column_names[i]);
        free(data->column_names);
    }
    if (data->column_types)
        free(data->column_types);
    if (data->data){
        for (int i = 0; i < data->nb_rows; i++) {
            for (int j = 0; j < data->nb_columns; j++)
                free(data->data[i][j]);
            free(data->data[i]);
        }
        free(data->data);
    }
    if (data->separator)
        free(data->separator);
    free(data);
}
