/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct value_type_s {
    int is_bool;
    int is_string;
    int is_int;
    int is_float;
    int is_uint;
} value_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    void ***data;
    char *separator;
} dataframe_t;

#endif
