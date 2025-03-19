/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** main.c
*/
#include "dataframe.h"

bool filter_func(void *value)
{
    return (*(int *)value > 30);
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("csv/data.csv", ",");
    dataframe_t *filtered = df_filter(dataframe ,"age", filter_func);
    printf("%s\n", (char *)filtered->data[0][0]);
    if (filtered != NULL)
        df_write_csv(filtered , "filtered.csv");
    return 0;
}
