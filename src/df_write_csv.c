/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_write_csv
*/

#include "my.h"
#include "dataframe.h"
#include <stdio.h>

void write_csv_header(FILE *file, dataframe_t *df)
{
    char *sep = df->separator;
    int n = df->nb_columns - 1;

    for (int i = 0; i < df->nb_columns; i++)
        fprintf(file, "%s%s", df->column_names[i], (i < n) ? sep : "");
    fprintf(file, "\n");
}

void write_csv_rows(FILE *file, dataframe_t *df)
{
    char **line = NULL;
    char **next = NULL;
    char *sep = df->separator;

    for (int i = 0; i < df->nb_rows; i++) {
        line = (char **)df->data[i];
        if (!line)
            continue;
        for (int j = 0; line[j] != NULL; j++)
            fprintf(file, "%s%s", line[j], (line[j + 1] != NULL) ? sep : "");
        next = (char **)df->data[i + 1];
        if (next != NULL && i < df->nb_rows - 1)
            fprintf(file, "\n");
    }
}

int df_write_csv(dataframe_t *df, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return 84;
    write_csv_header(file, df);
    write_csv_rows(file, df);
    fclose(file);
    return 0;
}
