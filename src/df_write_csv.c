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

static char *write_string(void *value, char *str, column_type_t type)
{
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
        default:
            break;
    }
    return str;
}

char *convert_to_string(void *value, column_type_t type)
{
    char *str = malloc(sizeof(char) * strlen((char *)value));

    if (!str)
        return NULL;
    if (type == STRING || type == UNDEFINED)
        return strdup((char *)value);
    else if (type == BOOL)
        return strdup(*(int *)value ? "true" : "false");
    str = write_string(value, str, type);
    return str;
}

void write_csv_rows(FILE *file, dataframe_t *df)
{
    char *sep = df->separator;
    char *valstr = NULL;

    for (int i = 0; i < df->nb_rows; i++) {
        for (int j = 0; j < df->nb_columns; j++) {
            valstr = convert_to_string(df->data[i][j], df->column_types[j]);
            fprintf(file, "%s", valstr ? valstr : "");
            free(valstr);
            fprintf(file, "%s", (j < df->nb_columns - 1) ? sep : "");
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
