/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** main
*/

#include "trigo.h"

static bool
isnum(char const *string)
{
    if (2 <= strln((char *)string)) return (false);
    if ('0' > *string || '9' < *string) return (false);
    return (true);
}

static bool
error_handling(int ac, char const * const *av)
{
    if (1 == ac) return (false);
    if (MAX_ARG_1 < ac) return (false);
    if (MAX_ARG_1 != ac && MAX_ARG_2 != ac) return (false);
    if (MAX_ARG_1 == ac && (!strcmp(av[1], MOD4) || !strcmp(av[1], MOD5))) return (false);
    if (MAX_ARG_2 == ac && (!strcmp(av[1], MOD1) || !strcmp(av[1], MOD2) || !strcmp(av[1], MOD3))) return (false);
    for (int i = 2; i != ac; i++)
        if (!isnum(av[i])) return (false);
    return (true);
}

static bool
trigo(int ac, char const * const *av)
{
    if (2 == ac && strcmp("-h", av[1]) == 0)
        if (!openf_readf("data/describe.txt")) return (false);
    if (!error_handling(ac, av)) return (false);
    return (true);
}

int
main(int ac, char const * const *av)
{
    return (!trigo(ac, av)) ? (EXIT_ERROR) : (EXIT_SUCCESS);
}