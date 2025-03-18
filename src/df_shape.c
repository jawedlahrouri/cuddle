/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_shape
*/

#
#include "dataframe.h"
#include <stdio.h>

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape = {0, 0};

    if (!dataframe)
        return shape;
    shape.nb_columns = dataframe->nb_columns;
    shape.nb_rows = dataframe->nb_rows;
    return shape;
}
