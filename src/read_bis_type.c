/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** read_bis_type
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void *switch2(column_type_t type, char **value)
{
    int *val_bool = malloc(sizeof(int));
    float *val_float = malloc(sizeof(float));

    if (!val_float || !val_bool) {
        free(val_float);
        free(val_bool);
        return NULL;
    }
    switch (type) {
        case FLOAT:
            *val_float = strtof(*value, NULL);
            return val_float;
        case BOOL:
            *val_bool = (strcmp(*value, "true") == 0) ? 1 : 0;
            return val_bool;
        default:
            return strdup(*value);
    }
}

void *convert_value(char *value, column_type_t type)
{
    void *result = NULL;
    int *val_int = 0;
    unsigned int *val_uint = 0;

    switch (type) {
        case INT:
            val_int = malloc(sizeof(int));
            if (!val_int)
                return NULL;
            *val_int = atoi(value);
            return val_int;
        case UINT:
            val_uint = malloc(sizeof(unsigned int));
            if (!val_uint)
                return NULL;
            *val_uint = (unsigned int)strtoul(value, NULL, 10);
            return val_uint;
        default:
            return switch2(type, &value);
    }
    return result;
}

char ***read_raw_data(FILE *file, char *separator, int *nb_row)
{
    char line[1024];
    char ***data = malloc(sizeof(char **) * 100);

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        data[*nb_row] = my_str_to_word_array(line, separator);
        (*nb_row)++;
    }
    return data;
}

dataframe_t *fill_dataframe(dataframe_t *data_frame,
    column_type_t *types, int nb_columns, int nb_row)
{
    data_frame->column_types = types;
    data_frame->nb_columns = nb_columns;
    data_frame->nb_rows = nb_row;
    return data_frame;
}

dataframe_t *fill_dataframe2(dataframe_t *data_frame,
    char **name, void ***data)
{
    data_frame->column_names = name;
    data_frame->data = data;
    return data_frame;
}
