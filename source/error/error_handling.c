/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** error_handling
*/

#include "trigo.h"

bool
error_handling(int ac, char const * const *av)
{
    if (1 == ac) return (false);
    if (MAX_ARG_1 < ac) return (false);
    if (MAX_ARG_1 != ac && MAX_ARG_2 != ac) return (false);
    if (MAX_ARG_1 == ac && !((!strcmp(av[1], MOD1) || !strcmp(av[1], MOD2)))) return (false);
    if (MAX_ARG_2 == ac && (!(!strcmp(av[1], MOD4) || !strcmp(av[1], MOD5) || !strcmp(av[1], MOD3)))) return (false);
    for (int i = 2; i != ac; i++)
        if (!isnum(av[i])) return (false);
    return (true);
}