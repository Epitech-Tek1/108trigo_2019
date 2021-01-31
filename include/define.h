/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define EXIT_ERROR 84
#define MOD1 "COS"
#define MOD2 "SIN"
#define MOD3 "EXP"
#define MOD4 "SINH"
#define MOD5 "COSH"
#define MAX_ARG_1 11
#define MAX_ARG_2 6
#define CONTENT trigo->content
#define MATRIX_EQUAL x + (y * CONTENT.size)
#define MATRIX_MUL_MAT1 i + (y * size)
#define MATRIX_MUL_MAT2 x + (i * size)
#define LIMITE 200

#define ADD_MATRIX(mat1, mat2) (mat1 += mat2)
#define DIV_MATRIX(mat1, k) (mat1[MATRIX_EQUAL] /= k)

typedef enum {RESULT = 0, TEMP = 1, CURRENT = 2} enum_process_t;

#endif /* !DEFINE_H_ */