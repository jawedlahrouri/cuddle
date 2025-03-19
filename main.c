/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** main.c
*/
#include "dataframe.h"

bool filter_func(void *value)
{
    printf("%s\n", (char *)value);
    return (*(int *)value > 30);
}

int main(void)
{
    dataframe_t *dataframe = df_read_csv("csv/data.csv", ",");
    df_info(dataframe);
    df_write_csv(dataframe, "file.s");
    return 0;
}
