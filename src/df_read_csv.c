/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_read_csv
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int is_it_bool(char ***arg, int nb_row, int i)
{
    int my_bool = 0;

    for (int j = 0; j < nb_row; j++) {
        if (strcmp(arg[j][i], "true") == 0 || strcmp(arg[j][i], "false") == 0)
            my_bool++;
    }
    return my_bool == nb_row ? 1 : 0;
}

static value_type_t *get_type(value_type_t *istype, int num)
{
    if (num == 1)
        istype->is_int++;
    if (num == 3)
        istype->is_float++;
    if (num == 0)
        istype->is_string++;
    if (num == 2)
        istype->is_uint++;
    return istype;
}

static int return_value(value_type_t *istype, int nb_row)
{
    if (istype->is_string > 0)
        return 5;
    if (istype->is_int == nb_row)
        return 2;
    if (istype->is_uint == nb_row)
        return 3;
    if (istype->is_float == nb_row)
        return 4;
    if (istype->is_bool == nb_row)
        return 1;
    return 0;
}

static int check_type(char ***arg, int i, int nb_row)
{
    int num = 0;
    value_type_t *istype = malloc(sizeof(value_type_t));

    if (!istype)
        return 0;
    istype->is_bool = 0;
    istype->is_string = 0;
    istype->is_int = 0;
    istype->is_float = 0;
    istype->is_uint = 0;
    for (int j = 0; j < nb_row; j++) {
        num = is_num(arg, nb_row, i);
        if (is_it_bool(arg, nb_row, i) == 1)
            istype->is_bool++;
        else
            istype = get_type(istype, num);
    }
    return return_value(istype, nb_row);
}

static void attribute_type(column_type_t *type, int i, int type_x)
{
    switch (type_x) {
        case 1:
            type[i] = BOOL;
            break;
        case 2:
            type[i] = INT;
            break;
        case 3:
            type[i] = UINT;
            break;
        case 4:
            type[i] = FLOAT;
            break;
        case 5:
            type[i] = STRING;
            break;
        default:
            type[i] = UNDEFINED;
            break;
    }
}

column_type_t *define_type(int nb_row, int nb_columns, char ***arg)
{
    column_type_t *type = malloc(sizeof(column_type_t) * nb_row);
    int type_x = 0;

    for (int i = 0; i < nb_columns; i++) {
        type_x = check_type(arg, i, nb_row);
        attribute_type(type, i, type_x);
    }
    return type;
}

column_type_t *set_to_undefined(int nb_columns)
{
    column_type_t *type = malloc(sizeof(column_type_t) * (nb_columns + 1));

    for (int i = 0; i < nb_columns; i++) {
        type[i] = UNDEFINED;
    }
    return type;
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

void ***convert_data(char ***raw_data,
    column_type_t *column_types, int nb_row, int nb_columns)
{
    void ***data = malloc(sizeof(void **) * nb_row);

    for (int i = 0; i < nb_row; i++) {
        data[i] = malloc(sizeof(void *) * nb_columns);
        for (int j = 0; j < nb_columns; j++) {
            data[i][j] = convert_value(raw_data[i][j], column_types[j]);
        }
    }
    return data;
}

dataframe_t *df_read_csv(char *filename, char *separator)
{
    dataframe_t *data_frame = malloc(sizeof(dataframe_t));
    FILE *file = fopen(filename, "r");
    int nb_row = 0;
    int nb_columns = 0;
    char **name;
    char ***raw_data;
    void ***data;
    column_type_t *types;

    separator = separator ? separator : ",";
    data_frame->separator = strdup(separator);
    if (!file || !data_frame)
        return NULL;
    name = read_column_names(file, separator, &nb_columns);
    raw_data = read_raw_data(file, separator, &nb_row);
    types = define_type(nb_row, nb_columns, raw_data);
    data = convert_data(raw_data, types, nb_row, nb_columns);
    data_frame = fill_dataframe2(data_frame, name, data);
    data_frame = fill_dataframe(data_frame, types, nb_columns, nb_row);
    return return_data_frame;
}
