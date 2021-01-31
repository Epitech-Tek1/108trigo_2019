/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** init
*/

#include "trigo.h"

bool
init(trigo_t *trigo, int ac, char const * const *av, int type)
{
    if (!(CONTENT.result = malloc(sizeof(double) * type))) return (false);
    if (!(CONTENT.content = malloc(sizeof(double) * type))) return (false);
    CONTENT.length = type;
    CONTENT.size = sqrt(type);
    for (int i = 2; ac > i; i++) CONTENT.content[i - 2] = atof(av[i]);
    return (true);
}