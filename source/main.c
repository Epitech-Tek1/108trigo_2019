/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** main
*/

#include "trigo.h"

static bool
trigo(int ac, char const * const *av)
{
    trigo_t trigo;

    if (2 == ac && strcmp("-h", av[1]) == 0)
        if (!openf_readf("data/describe.txt")) return (false);
    if (!error_handling(ac, av)) return (false);
    if (!init(&trigo, ac, av, ac - 2)) return (false);
    if (!process(&trigo, ac - 2, (string)av[1])) return (false);
    display(trigo);
    _free(&trigo);
    return (true);
}

int
main(int ac, char const * const *av)
{
    return (!trigo(ac, av)) ? (EXIT_ERROR) : (EXIT_SUCCESS);
}