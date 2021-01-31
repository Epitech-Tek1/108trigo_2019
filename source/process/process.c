/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** process
*/

#include "trigo.h"

static bool
process_exp(trigo_t *trigo, process_t *process)
{
    CONTENT.fac = 1;
    if (!get_matrix(trigo, process)) return (false);
    memcpy(process[RESULT].dval, CONTENT.content, sizeof(double) * CONTENT.length);
    if (!(CONTENT.result = add(CONTENT.result, CONTENT.content, CONTENT.length))) return (false);
    for (int i = 2; LIMITE > i; i++) {
        memcpy(process[CURRENT].dval, CONTENT.result, CONTENT.length);
        if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        CONTENT.fac *= i;
        memcpy(process[TEMP].dval, process[RESULT].dval, sizeof(double) * CONTENT.length);
        if (!(process[TEMP].dval = _div(process[TEMP].dval, CONTENT.fac, CONTENT.length, CONTENT.size, trigo))) return (false);
        if (!(CONTENT.result = add(CONTENT.result, process[TEMP].dval, CONTENT.length))) return (false);
        free(process[TEMP].dval);
        if (reduced_equation(trigo)) break;
    }
    return (true);
}

static bool
process_cos(trigo_t *trigo, process_t *process)
{
    CONTENT.fac = 2;
    if (!get_matrix(trigo, process)) return (false);
    memcpy(process[RESULT].dval, CONTENT.content, sizeof(double) * CONTENT.length);
    for (int i = 2, n = 2; LIMITE > i; i++) {
        memcpy(process[CURRENT].dval, CONTENT.result, sizeof(double) * CONTENT.length);
        if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        memcpy(process[TEMP].dval, process[RESULT].dval, sizeof(double) * CONTENT.length);
        if (!(process[TEMP].dval = _div(process[TEMP].dval, CONTENT.fac, CONTENT.length, CONTENT.size, trigo))) return (false);
        if (!(CONTENT.result = (i % 2) ? add(CONTENT.result, process[TEMP].dval, CONTENT.length) : sub(CONTENT.result, process[TEMP].dval, CONTENT.length))) return (false);
        free(process[TEMP].dval);
        if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        CONTENT.fac *= ++n, CONTENT.fac *= ++n;
        if (reduced_equation(trigo)) break;
    }
    return (true);
}

static bool
process_sin(trigo_t *trigo, process_t *process)
{
    CONTENT.fac = 6;
    memcpy(process[RESULT].dval, CONTENT.content, sizeof(double) * CONTENT.length);
    memcpy(CONTENT.result, CONTENT.content, sizeof(double) * CONTENT.length);
    for (int i = 2, n = 3; LIMITE > i; i++) {
        memcpy(process[CURRENT].dval, CONTENT.result, sizeof(double) * CONTENT.length);
        for (int n = 0; 2 != n; n++) if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        memcpy(process[TEMP].dval, process[RESULT].dval, sizeof(double) * CONTENT.length);
        if (!(process[TEMP].dval = _div(process[TEMP].dval, CONTENT.fac, CONTENT.length, CONTENT.size, trigo))) return (false);
        if (!(CONTENT.result = (i % 2) ? add(CONTENT.result, process[TEMP].dval, CONTENT.length) : sub(CONTENT.result, process[TEMP].dval, CONTENT.length))) return (false);
        free(process[TEMP].dval);
        CONTENT.fac *= ++n, CONTENT.fac *= ++n;
        if (reduced_equation(trigo)) break;
    }
    return (true);
}

static bool
process_cosh(trigo_t *trigo, process_t *process)
{
    CONTENT.fac = 2;
    if (!get_matrix(trigo, process)) return (false);
    memcpy(process[RESULT].dval, CONTENT.content, sizeof(double) * CONTENT.length);
    for (int i = 2, n = 2; LIMITE > i; i++) {
        memcpy(process[CURRENT].dval, CONTENT.result, sizeof(double) * CONTENT.length);
        if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        memcpy(process[TEMP].dval, process[RESULT].dval, sizeof(double) * CONTENT.length);
        if (!(process[TEMP].dval = _div(process[TEMP].dval, CONTENT.fac, CONTENT.length, CONTENT.size, trigo))) return (false);
        if (!(CONTENT.result = add(CONTENT.result, process[TEMP].dval, CONTENT.length))) return (false);
        if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        free(process[TEMP].dval);
        CONTENT.fac *= ++n, CONTENT.fac *= ++n;
        if (reduced_equation(trigo)) break;
    }
    return (true);
}

static bool
process_sinh(trigo_t *trigo, process_t *process)
{
    CONTENT.fac = 6;
    memcpy(process[RESULT].dval, CONTENT.content, sizeof(double) * CONTENT.length);
    memcpy(CONTENT.result, CONTENT.content, sizeof(double) * CONTENT.length);
    for (int i = 2, n = 3; LIMITE > i; i++) {
        memcpy(process[CURRENT].dval, CONTENT.result, sizeof(double) * CONTENT.length);
        for (int n = 0; 2 != n; n++) if (!(process[RESULT].dval = mul_matrix(process[RESULT].dval, CONTENT.content, CONTENT.length, CONTENT.size))) return (false);
        memcpy(process[TEMP].dval, process[RESULT].dval, sizeof(double) * CONTENT.length);
        if (!(process[TEMP].dval = _div(process[TEMP].dval, CONTENT.fac, CONTENT.length, CONTENT.size, trigo))) return (false);
        if (!(CONTENT.result = add(CONTENT.result, process[TEMP].dval, CONTENT.length))) return (false);
        free(process[TEMP].dval);
        CONTENT.fac *= ++n, CONTENT.fac *= ++n;
        if (reduced_equation(trigo)) break;
    }
    return (true);
}

bool
process(trigo_t *trigo, int type, string stype)
{
    char *ttype[] = {"EXP", "COS", "SIN", "COSH", "SINH"};

    if (!(CONTENT.process = malloc(sizeof(process_t) * 4))) return (false);
    for (int i = 0; 4 != i; i++)
        if (!(CONTENT.process[i].dval = malloc(sizeof(double) * CONTENT.length))) return (false);
    bool (*function_array[])(trigo_t *, process_t *) = {
        process_exp,
        process_cos,
        process_sin,
        process_cosh,
        process_sinh
    };
    for (int i = 0; 5 != i; i++)
        if (!strcmp(stype, ttype[i])) function_array[i](trigo, trigo->content.process);
    return (true);
}