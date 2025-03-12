/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

static int alphanum(char c, char specifie)
{
    if (c == specifie)
        return 0;
    return 1;
}

static int nb_of_words(char const *str, char specifie)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (alphanum(str[i], specifie) == 1 && (i == 0 ||
            alphanum(str[i - 1], specifie) == 0))
            count++;
    return count + 1;
}

static int len_next_word(char const *str, int i, char specifie)
{
    int count = 0;

    while (str[i] != '\0' && alphanum(str[i], specifie) == 1) {
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

int word_array(word_array_t *value, char specifie, int *i, int a)
{
    static int j = 0;

    if (alphanum(value->str[a], specifie) == 1 && (a == 0 ||
        alphanum(value->str[a - 1], specifie) == 0)) {
        (*i)++;
        j = 0;
        value->array[*i] = malloc(sizeof(char) *
            len_next_word(value->str, a, specifie));
        if (!value->array[*i])
            return 0;
    }
    if (alphanum(value->str[a], specifie) == 1) {
        value->array[*i][j] = value->str[a];
        j++;
        value->array[*i][j] = '\0';
    }
    return 1;
}

char **my_str_to_word_array(char const *str, char specifie)
{
    int i = -1;
    int word_count = nb_of_words(str, specifie);
    word_array_t value;

    value.str = str;
    value.array = malloc(sizeof(char *) * (word_count + 1));
    if (!value.array)
        return NULL;
    for (int a = 0; value.str[a] != '\0'; a++) {
        if (!word_array(&value, specifie, &i, a)) {
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
