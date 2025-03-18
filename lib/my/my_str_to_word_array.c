/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "dataframe.h"

static int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i])
            return 1;
    }
    return 0;
}

static int nb_of_words(char const *str, char *separators)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!is_separator(str[i], separators) && (i == 0 ||
            is_separator(str[i - 1], separators)))
            count++;
    return count + 1;
}

static int len_next_word(char const *str, int i, char *separators)
{
    int count = 0;

    while (str[i] != '\0' && !is_separator(str[i], separators)) {
        i++;
        count++;
    }
    return count + 1;
}

static char **free_array(char **array, int size)
{
    if (!array)
        return NULL;
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
    return NULL;
}

int word_array(word_array_t *value, char *separators, int *i, int a)
{
    static int j = 0;

    if (!is_separator(value->str[a], separators) && (a == 0 ||
        is_separator(value->str[a - 1], separators))) {
        (*i)++;
        j = 0;
        value->array[*i] = malloc(sizeof(char) *
            len_next_word(value->str, a, separators));
        if (!value->array[*i])
            return 0;
    }
    if (!is_separator(value->str[a], separators)) {
        value->array[*i][j] = value->str[a];
        j++;
        value->array[*i][j] = '\0';
    }
    return 1;
}

char **my_str_to_word_array(char const *str, char *separators)
{
    int i = -1;
    int word_count = nb_of_words(str, separators);
    word_array_t value;

    value.str = str;
    value.array = malloc(sizeof(char *) * (word_count + 1));
    if (!value.array)
        return NULL;
    for (int a = 0; value.str[a] != '\0'; a++) {
        if (!word_array(&value, separators, &i, a)) {
            return free_array(value.array, i + 1);
        }
    }
    if (i == -1) {
        free(value.array);
        return NULL;
    }
    value.array[i + 1] = NULL;
    return value.array;
}
