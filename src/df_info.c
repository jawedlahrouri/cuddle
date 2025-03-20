/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** fd_info
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void df_info(dataframe_t *dataframe)
{
    const char *type_names[] = {"bool", "int",
        "unsigned int", "float", "string", "undefined"};

    printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++){
        printf("- %s: %s\n", dataframe->column_names[i],
            type_names[dataframe->column_types[i]]);
    }
}
