/*
** EPITECH PROJECT, 2020
** 108trigo_2019 [WSL: Debian]
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

typedef char * string;

static inline bool
isnum(char const *string)
{
    if (2 <= strln((char *)string)) return (false);
    if ('0' > *string || '9' < *string) return (false);
    return (true);
}

bool
error_handling(int ac, char const * const *av);

bool
init(trigo_t *trigo, int ac, char const * const *av, int type);

bool
process(trigo_t *trigo, int type, string stype);

double *
add(double *mat1, double *mat2, size_t length);

double *
sub(double *mat1, double *mat2, size_t length);

double *
mul_matrix(double *mat1, double *mat2, size_t length, size_t size);

double *
_div(double *mat1, double k, size_t length, size_t size, trigo_t *trigo);

bool
reduced_equation(trigo_t *trigo);

bool
get_matrix(trigo_t *trigo, process_t *process);

void
display(trigo_t trigo);

bool
_free(trigo_t *trigo);

#endif /* !FUNCTION_H_ */