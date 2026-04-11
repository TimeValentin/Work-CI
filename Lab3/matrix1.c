#include "matrix.h"
#include <stdlib.h>

/*int x, i, j, n, m, k;*/


double** locate_matrix(int n) 
{
	int i;
    double **res = (double**)malloc(n * sizeof(double*)); 
    for (i = 0; i < n; i++) 
	{
        res[i] = (double*)malloc(n * sizeof(double));
    }
    return res;
}


void free_matrix(double** mat, int n)
{
	int i;
	for (i=0; i < n; i++)
	{
		free (mat[i]);
	}
	free (mat);
	
}


double** summ(double **a, double **b, int n) 
{
    double **res = locate_matrix(n);
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

double** sub(double **a, double **b, int n) {
    double **res = locate_matrix(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
} 

double** mult(double **a, double **b, int n) {
    double **res = locate_matrix(n);
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            res[i][j] = 0;
            for (k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}


