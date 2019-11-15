/*
 * (C) Copr. 1986-92 Numerical Recipes Software ?421.1-9.

 * Códigos obtidos no livro "Numerical Recipes in C"
 * Os código aqui presentes foram levemente modificados para funcionar
 * indepentendemente dos códigos presentes no livro, mas os direitos
 * autorais continuam sendo dos autores originais.

*/

#ifndef NUMERICALRECIPES_H
#define NUMERICALRECIPES_H

#include "util.h"
#define TINY 1.0e-20;

void ludcmp(float a[][MAX], int n, int *indx, float *d);
void lubksb(float a[][MAX], int n, int *indx, float b[]);

#endif // NUMERICALRECIPES_H
