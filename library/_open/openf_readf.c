/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** describe
*/

#include "openf.h"

static bool
init_openf(openf_t *openf, string filepath)
{
    openf->lineptr = NULL;
    openf->n = 500;
    if (!(openf->stream = fopen(filepath, "r"))) {
        write(2, "failed to load file. Check the filepath\n", 40);
        return (false);
    }
    return (true);
}

bool
openf_readf(string filepath)
{
    openf_t openf;

    if (!init_openf(&openf, filepath)) return (false);
    while (-1 != getline(&openf.lineptr, &openf.n, openf.stream))
        write(1, openf.lineptr, strln(openf.lineptr));
    return (true);
}