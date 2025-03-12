/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_write_csv
*/

#include "my.h"
#include "dataframe.h"
#include <stdio.h>

int df_write_csv(dataframe_t *dataframe ,const char *filename)
{
    FILE *file = fopen(filename, "w");
    char **line = NULL;
    char *sep = dataframe->separator;

    printf("befor\n");
    if (file == NULL)
        return 84;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        line = (char **)dataframe->data[i];
        if (line == NULL)
            break;
        for (int j = 0; line[j] != NULL; j++) {
            printf("%s\n", line[j]);
            fprintf(file, "%s%s", line[j], (line[j + 1] != NULL) ? sep : "");
            }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}

#include "my.h"
#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>

void print_column_types(column_type_t *column_types, int nb_columns)
{
    printf("Types des colonnes :\n");
    for (int i = 0; i < nb_columns; i++) {
        printf("Colonne %d : %u\n", i, column_types[i]);
    }
    printf("\n");
}
