/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_write_csv
*/

#include "my.h"
#include "dataframe.h"
#include <stdio.h>

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = fopen(filename, "w");
    char **line = NULL;
    char *sep = dataframe->separator;
    char **columns = dataframe->column_names;

    if (file == NULL)
        return 84;
    for (int i = 0; columns[i] != NULL; i++)
        fprintf(file, "%s%s", columns[i], (columns[i + 1] != NULL) ? sep : "");
    fprintf(file, "\n");
    for (int i = 0; i < dataframe->nb_rows; i++) {
        line = (char **)dataframe->data[i];
        if (line == NULL)
            break;
        for (int j = 0; line[j] != NULL; j++)
            fprintf(file, "%s%s", line[j], (line[j + 1] != NULL) ? sep : "");
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}
