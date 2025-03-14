/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_read_csv
*/

#include "dataframe.h"
#include <stdint.h>
#include "my.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int is_negative(char *str)
{
    return str[0] == '-';
}

static int is_valid_digit(char c)
{
    return (c >= '0' && c <= '9') || c == '.';
}

int count_points(char *str)
{
    int point = 0;

    for (int a = 0; str[a]; a++) {
        if (str[a] == '.')
            point++;
    }
    return point;
}

static int next(char ***arg, int i, int j, int *is_float)
{
    for (int a = 0; arg[j][i][a]; a++) {
        if (!is_valid_digit(arg[j][i][a]))
            return 0;
        if (arg[j][i][a] == '.')
            *is_float = 1;
    }
    return 1;
}

int is_num(char ***arg, int nb_row, int i)
{
    int is_float = 0;

    for (int j = 0; j < nb_row; j++) {
        if (is_negative(arg[j][i]))
            return 2;
        int point = count_points(arg[j][i]);
        if (point > 1)
            return 84;
        if (next(arg, i, j, &is_float) == 0)
            return 0;
    }
    return is_float ? 3 : 1;
}

int is_it_bool(char ***arg, int nb_row, int i)
{
    int my_bool = 0;

    for (int j = 0; j < nb_row; j++) {
        if (strcmp(arg[j][i], "true") == 0 || strcmp(arg[j][i], "false") == 0)
            my_bool++;
    }
    return my_bool == nb_row ? 1 : 0;
}

int check_type(char ***arg, int i, int nb_row)
{
    int is_bool = 0;
    int is_string = 0;
    int is_int = 0;
    int is_float = 0;
    int is_uint = 0;
    int num = 0;

    for (int j = 0; j < nb_row; j++) {
        num = is_num(arg, nb_row, i);
        if (is_it_bool(arg, nb_row, i) == 1)
            is_bool++;
        else if (num == 1)
            is_int++;
        else if (num == 3)
            is_float++;
        else if (num == 0)
            is_string++;
        else if (num == 2)
            is_uint++;
    }
    if (is_string > 0)
        return 5;
    if (is_int == nb_row)
        return 2;
    if (is_uint == nb_row)
        return 3;
    if (is_float == nb_row)
        return 4;
    if (is_bool == nb_row)
        return 1;
    return 0;
}

column_type_t *define_type(int nb_row, int nb_columns, char ***arg)
{
    column_type_t *type = malloc(sizeof(column_type_t) * nb_row);
    int type_x = 0;

    for (int i = 0; i < nb_columns; i++) {
        type_x = check_type(arg, i, nb_row);
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
    return type;
}

column_type_t *set_to_undefined(int nb_row, int nb_columns)
{
    column_type_t *type = malloc(sizeof(column_type_t) * nb_row);

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

void ***read_data(FILE *file, char *separator, int *nb_row)
{
    char line[1024];
    void ***data = malloc(sizeof(void **) * 100);

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        data[*nb_row] = (void **)my_str_to_word_array(line, separator);
        (*nb_row)++;
    }
    return data;
}

dataframe_t *df_read_csv(char *filename, char *separator)
{
    dataframe_t *data_frame = malloc(sizeof(dataframe_t));
    FILE *file = fopen(filename, "r");
    int nb_row = 0, nb_columns = 0;
    char **name;
    void ***data;

    if (!file || !data_frame)
        return NULL;
    name = read_column_names(file, separator, &nb_columns);
    data = read_data(file, separator, &nb_row);
    data_frame->column_names = name;
    data_frame->data = data;
    data_frame->column_types = define_type(nb_row, nb_columns, (char ***)data);
    data_frame->nb_columns = nb_columns;
    data_frame->nb_rows = nb_row;
    data_frame->separator = separator;
    fclose(file);
    return data_frame;
}
