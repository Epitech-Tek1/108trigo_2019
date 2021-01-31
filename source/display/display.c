/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** display
*/

#include "trigo.h"
#undef MATRIX_EQUAL
#define MATRIX_EQUAL x + (y * trigo.content.size)

void
display(trigo_t trigo)
{
    for (int y = 0; trigo.content.size > y; y++)
        for (int x = 0; trigo.content.size > x; x++) {
            printf("%.2f", trigo.content.result[MATRIX_EQUAL]), printf((x == trigo.content.size - 1) ? "\n" : "\t");
        }
}