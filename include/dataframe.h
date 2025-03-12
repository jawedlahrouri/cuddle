/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe
*/

#ifndef dataframe_h
    #define dataframe_h

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows; // Number of rows in the dataframe
    int nb_columns; // Number of columns in the dataframe
    char **column_names; // Array of column names
    column_type_t *column_types; // Array of column types
    void ***data; // 2D array of data values
} dataframe_t;

#endif
