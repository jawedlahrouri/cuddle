/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** main
*/

#include "my.h"
#include "dataframe.h"
#include <stdio.h>

int main(void)
{
    dataframe_t *dataframe;

    dataframe = df_read_csv("file.csv", ",");
    df_info(dataframe);
    return 0;
}
