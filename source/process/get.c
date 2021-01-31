/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** get
*/

#include "trigo.h"

bool
reduced_equation(trigo_t *trigo)
{
    for (int i = 0; CONTENT.length > i; i++)
        if (CONTENT.result[i] != CONTENT.process[CURRENT].dval[i]) goto empty;
    goto ret;
    empty:
        for (int i = 0; CONTENT.length > i; i++)
            if (CONTENT.result[i] != 0) return (false);
        memcpy(CONTENT.result, CONTENT.process[CURRENT].dval, CONTENT.length);
    ret:
        return (true);
}

bool
get_matrix(trigo_t *trigo, process_t *process)
{
    int y = -1;
    int x = 0;

    if (!(CONTENT.result = malloc(sizeof(double) * CONTENT.length))) return (false);
    _while_y:
        y++;
        if (CONTENT.size <= y) goto ret;
        _while_x:
            if (CONTENT.size <= x) {x = 0; goto _while_y;}
            CONTENT.result[MATRIX_EQUAL] = (y == x) ? (1) : (0);
            x++;
            goto _while_x;

    ret:
        return (true);
}

double *
add(double *mat1, double *mat2, size_t length)
{
    int i = 0;
    double *mat_tmp = NULL;

    if (!(mat_tmp = malloc(sizeof(double) * length))) return (NULL);
    _for:
        if (length <= i) goto _ret;
        mat_tmp[i] = mat1[i] + mat2[i];
        i++;
        goto _for;

    _ret:
        return (mat_tmp);
}

double *
sub(double *mat1, double *mat2, size_t length)
{
    int i = 0;
    double *mat_tmp = NULL;

    if (!(mat_tmp = malloc(sizeof(double) * length))) return (NULL);
    _for:
        if (length <= i) goto _ret;
        mat_tmp[i] = mat1[i] - mat2[i];
        i++;
        goto _for;

    _ret:
        return (mat_tmp);
}

double *
_div(double *mat1, double k, size_t length, size_t size, trigo_t *trigo)
{
    int y = -1;
    int x = 0;
    double *mat_tmp = NULL;

    if (!(mat_tmp = malloc(sizeof(double) * length))) return (NULL);
    _while_y:
        y++;
        if (CONTENT.size <= y) goto ret;
        _while_x:
            if (CONTENT.size <= x) {x = 0; goto _while_y;}
            mat_tmp[MATRIX_EQUAL] = mat1[MATRIX_EQUAL] / k;
            x++;
            goto _while_x;

    ret:
        return (mat_tmp);
}

double *
mul_matrix(double *mat1, double *mat2, size_t length, size_t size)
{
    double *result = NULL;
	double tmp;

    if (!(result = malloc(sizeof(double) * length))) return (NULL);
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			tmp = 0;
			for (int i = 0; i < size; i++) tmp += mat1[(y * size) + i] * mat2[(size * i) + x];
			result[x + (y * size)] = tmp;
		}
	}
	return (result);
}