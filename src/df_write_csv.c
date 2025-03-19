/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_write_csv
*/

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

char *convert_to_string(void *value, column_type_t type)
{
    char *str = malloc(sizeof(char) * strlen((char *)value));

    if (!str)
        return NULL;
    switch (type) {
        case INT:
            sprintf(str, "%d", *(int *)value);
            break;
        case UINT:
            sprintf(str, "%u", *(unsigned int *)value);
            break;
        case FLOAT:
            sprintf(str, "%.2f", *(float *)value);
            break;
        case BOOL:
            sprintf(str, "%s", (*(int *)value) ? "true" : "false");
            break;
        case STRING:
        default:
            return strdup((char *)value);
    }
    return str;
}

void write_csv_rows(FILE *file, dataframe_t *df)
{
    char *sep = df->separator;
    char *value_str = NULL;

    for (int i = 0; i < df->nb_rows; i++) {
        for (int j = 0; j < df->nb_columns; j++) {
            value_str = convert_to_string(df->data[i][j], df->column_types[j]);
            if (!value_str)
                continue;
            fprintf(file, "%s%s", value_str, (j < df->nb_columns - 1) ? sep : "");
            free(value_str);
        }
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
