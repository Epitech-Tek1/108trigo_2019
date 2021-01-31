/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** openf_function
*/

#ifndef OPENF_FUNCTION_H_
#define OPENF_FUNCTION_H_

static inline size_t
strln(string string)
{
    char *ptr = string;

    for (; *ptr; ptr++);
    return ptr - string;
}

bool
openf_readf(string filepath);

#endif /* !OPENF_FUNCTION_H_ */