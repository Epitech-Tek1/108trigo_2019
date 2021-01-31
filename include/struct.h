/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct process_s
{
    double *dval;
} process_t;

typedef struct root_s
{
    process_t *process;
    double *content;
    double *result;
    double fac;
    size_t length;
    size_t size;
} root_t;


typedef struct trigo_s
{
    root_t content;
} trigo_t;


#endif /* !STRUCT_H_ */