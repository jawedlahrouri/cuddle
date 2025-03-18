/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe
*/

#include "dataframe.h"
#include <math.h>

static double find_mean(dataframe_t *dataframe, int i)
{
    double total = 0;

    for (int j = 0; j < dataframe->nb_rows; j++)
        total += atof(dataframe->data[j][i]);
    return total / dataframe->nb_rows;
}

static double calcul_std(dataframe_t *dataframe, int i, double mean)
{
    double total = 0;

    for (int j = 0; j < dataframe->nb_rows; j++){
        total += pow((atof(dataframe->data[j][i]) - mean), 2);
    }
    total = total / (dataframe->nb_rows);
    total = sqrt(total);
    return total;
}

static double find_max(dataframe_t *dataframe, int i)
{
    double max = atof(dataframe->data[0][i]);

    for (int j = 0; j < dataframe->nb_rows; j++){
        if (max < atof(dataframe->data[j][i]))
            max = atof(dataframe->data[j][i]);
    }
    return max;
}

static double find_min(dataframe_t *dataframe, int i)
{
    double min = atof(dataframe->data[0][i]);

    for (int j = 0; j < dataframe->nb_rows; j++){
        if (min > atof(dataframe->data[j][i]))
            min = atof(dataframe->data[j][i]);
    }
    return min;
}

void display_describe_info(dataframe_t *dataframe, int i)
{
    double mean = find_mean(dataframe, i);

    printf("Column: %s\n", dataframe->column_names[i]);
    printf("Count: %d\n", dataframe->nb_columns);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", calcul_std(dataframe, i, mean));
    printf("Min: %.2f\n", find_min(dataframe, i));
    printf("Max: %.2f\n", find_max(dataframe, i));
}

void df_describe(dataframe_t *dataframe)
{
    for (int i = 0; dataframe->column_types[i]; i++)
        if (dataframe->column_types[i] == (1 || 2 || 3))
            display_describe_info(dataframe, i);
}
