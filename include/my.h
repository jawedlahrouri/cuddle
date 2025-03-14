/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** my
*/
#ifndef MY_H
    #define MY_H

    #include "dataframe.h"

typedef struct word_array_s {
    char **array;
    char const *str;
} word_array_t;

char **my_str_to_word_array(char const *str, char *separators);
dataframe_t *df_read_csv(char *filename, char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);
void df_info(dataframe_t *dataframe);

#endif
