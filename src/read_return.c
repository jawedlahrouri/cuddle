/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** read_return
*/

#include "dataframe.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


dataframe_t *return_data_frame(FILE *file, dataframe_t *data_frame)
{
    fclose(file);
    return data_frame;
}
