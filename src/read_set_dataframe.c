/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** read_set_dataframe
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void free_raw_data(char ***raw_data)
{
    if (!raw_data)
        return;
    for (int i = 0; raw_data[i]; i++) {
        for (int j = 0; raw_data[i][j]; j++)
            free(raw_data[i][j]);
        free(raw_data[i]);
    }
    free(raw_data);
}

char **read_column_names(FILE *file, char *separator, int *nb_columns)
{
    char line[1024];
    char **name = NULL;

    if (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        name = my_str_to_word_array(line, separator);
        while (name[*nb_columns])
            (*nb_columns)++;
    }
    return name;
}
