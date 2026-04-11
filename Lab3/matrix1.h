#ifndef MATRIX_H
#define MATRIX_H

int x, i, j, n, m, k;


double** summ(double **a, double **b, int x);
double** sub(double **a, double **b, int x);
double** mult(double **a, double **b, int x);
double** locate_matrix(int n);
void free_matrix(double** mat, int n);

#endif
