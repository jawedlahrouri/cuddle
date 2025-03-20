/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe
*/

#include "dataframe.h"
#include <math.h>

static double find_mean(dataframe_t *dataframe, int i, int type)
{
    double total = 0;

    if (type == 1)
        for (int j = 0; j < dataframe->nb_rows; j++) {
            total += *(int *)dataframe->data[j][i];
        }
    if (type == 3)
        for (int j = 0; j < dataframe->nb_rows; j++) {
            total += *(float *)dataframe->data[j][i];
        }
    return total / dataframe->nb_rows;
}

static double calcul_std(dataframe_t *dataframe, int i, double mean, int type)
{
    double total = 0;

    if (type == 1)
        for (int j = 0; j < dataframe->nb_rows; j++){
            total += pow((*(int *)dataframe->data[j][i] - mean), 2);
        }
    if (type == 3)
        for (int j = 0; j < dataframe->nb_rows; j++){
            total += pow((*(float *)dataframe->data[j][i] - mean), 2);
        }
    total = total / (dataframe->nb_rows);
    total = sqrt(total);
    return total;
}

int max_min_int(int max, int nbr, int type)
{
    if (type == 1)
        if (max < nbr)
            max = nbr;
    if (type == 2)
        if (max > nbr)
        max = nbr;
    return max;
}

double max_min_float(double max, double nbr, int type)
{
    if (type == 1)
        if (max < nbr)
            max = nbr;
    if (type == 2)
        if (max > nbr)
        max = nbr;
    return max;
}

static double find_max(dataframe_t *dataframe, int i, int type)
{
    double max = 0;

    if (type == 1) {
        max = *(int *)dataframe->data[0][i];
        for (int j = 0; j < dataframe->nb_rows; j++){
            max = max_min_int(max, *(int *)dataframe->data[j][i], 1);
        }
    }
    if (type == 3) {
        max = *(float *)dataframe->data[0][i];
        for (int j = 0; j < dataframe->nb_rows; j++){
            max = max_min_float(max, *(float *)dataframe->data[j][i], 1);
        }
    }
    return max;
}

static double find_min(dataframe_t *dataframe, int i, int type)
{
    double min = 0;

    if (type == 1) {
        min = *(int *)dataframe->data[0][i];
        for (int j = 0; j < dataframe->nb_rows; j++){
            min = max_min_int(min, *(int *)dataframe->data[j][i], 2);
        }
    }
    if (type == 3) {
        min = *(float *)dataframe->data[0][i];
        for (int j = 0; j < dataframe->nb_rows; j++){
            min = max_min_float(min, *(float *)dataframe->data[j][i], 2);
        }
    }
    return min;
}

void display_describe_info(dataframe_t *dataframe, int i, int type)
{
    double mean = find_mean(dataframe, i, type);

    printf("Column: %s\n", dataframe->column_names[i]);
    printf("Count: %d\n", dataframe->nb_rows);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", calcul_std(dataframe, i, mean, type));
    printf("Min: %.2f\n", find_min(dataframe, i, type));
    printf("Max: %.2f\n", find_max(dataframe, i, type));
}

void df_describe(dataframe_t *dataframe)
{
    for (int i = 0; dataframe->column_types[i]; i++){
        printf("%d\n", dataframe->column_types[i]);
        if (dataframe->column_types[i] == 1 ||
            dataframe->column_types[i] == 2 ||
            dataframe->column_types[i] == 3)
            display_describe_info(dataframe, i, dataframe->column_types[i]);
    }
}
