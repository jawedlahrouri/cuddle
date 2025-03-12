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

#include <stdio.h>

// BOOL,
// INT,
// UINT,
// FLOAT,
// STRING,
// UNDEFINED


column_type_t *define_type(int nb_row, char **arg)
{
    column_type_t *type = malloc(sizeof(column_type_t) * nb_row);
    int type_x = 0;

    for (int j = 0; j < nb_row; j++){
        type_x = check_type(arg[j]);
        switch (type_x)
        {
        case 1:
            type[j] = BOOL;
        case 2:
            type[j] = INT;
        case 3:
            type[j] = UINT;
        case 4:
            type[j] = FLOAT;
        case 5:
            type[j] = STRING;
        case 6:
            type[j] = INT;
        default:
            break;
        }                                                                                                                                               
    }
    type[0] = STRING;
    type[1] = INT;
    type[2] = STRING;
    return type;
}

dataframe_t *df_read_csv(const char *filename, const char separator)
{
    dataframe_t *data_frame = malloc(sizeof(dataframe_t));
    if (!data_frame)
        return NULL;
    FILE *file = fopen(filename, "r");
    if (!file)
        return NULL;
    char line[1024];
    int nb_row = 0;
    int nb_columns = 0;
    void ***data = malloc(sizeof(void **) * 100);

    if (!data)
        return NULL;
    if (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        data[nb_row++] = (void **)my_str_to_word_array(line, separator);
        while (data[0][nb_columns])
            nb_columns++;
    }
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        data[nb_row++] = (void **)my_str_to_word_array(line, separator);
    }
    data_frame->column_names = (char **)data[0];
    data_frame->column_types = define_type(nb_row - 1, (char **)data[1]);
    data_frame->nb_columns = nb_columns;
    data_frame->nb_rows = nb_row - 1;
    data_frame->data = data;
    fclose(file);
    return data_frame;
}

int main(int ac, char **av)
{
    dataframe_t *data;
    if (ac == 2){
        data = df_read_csv(av[1], ',');
        printf("%d\n", data->nb_columns);
        return 0;
    }
    return 84;
}
