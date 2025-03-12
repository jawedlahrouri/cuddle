/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** my
*/
#ifndef my_h
    #define my_h

typedef struct word_array_s {
    char **array;
    char const *str;
} word_array_t;

char **my_str_to_word_array(char const *str, char specifie);

#endif