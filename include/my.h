/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** my
*/
#ifndef my_h
    #define my_h

#include "dataframe.h"

typedef struct word_array_s {
    char **array;
    char const *str;
} word_array_t;

char **my_str_to_word_array(char const *str, char *separators);
dataframe_t *df_read_csv(char *filename, char *separator);
int df_write_csv(dataframe_t *dataframe ,const char *filename);
#endif
