/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** my
*/
#ifndef MY_H
    #define MY_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include "dataframe.h"

typedef struct word_array_s {
    char **array;
    char const *str;
} word_array_t;

void df_free(dataframe_t *data);
dataframe_t *df_tail(dataframe_t *df, int nb_rows);
dataframe_t *df_head(dataframe_t *df, int nb_rows);
char **my_str_to_word_array(char const *str, char *separators);
dataframe_t *df_read_csv(char *filename, char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);
void df_info(dataframe_t *dataframe);
int is_num(char ***arg, int nb_row, int i);
int check_error(char ***arg, int i, int j, int *is_float);
int count_points(char *str);
int is_valid_digit(char c);
int is_negative(char *str);
dataframe_shape_t df_shape(dataframe_t *dataframe);

#endif
