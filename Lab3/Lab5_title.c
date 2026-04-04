#include <stdlib.h>
#include <stdio.h>
#include "Lab5_title.h"



double** allocate_matrix(int n) 
{
    double** matrix = (double**)malloc(n * sizeof(double*));
    
	for (i = 0; i < n; i++) 
	{
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

void matrix(double** matrix, int n) 
{
    for (i = 0; i < n; i++) 
	{
        free(matrix[i]);
    }
    free(matrix);
}


double** calculate(double** a, double** b, int n, char op) 
{
    double** res = (double**)malloc(n * sizeof(double*));
    for ( i = 0; i < n; i++) 
	{
        res[i] = (double*)malloc(n * sizeof(double));
    }
 
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            if (op == '+') 
			{
                res[i][j] = a[i][j] + b[i][j];
            } 
			else if (op == '-') 
			{
                res[i][j] = a[i][j] - b[i][j];
            } 
			else if (op == '*') 
			{
                res[i][j] = 0;
                for (int k = 0; k < n; k++) 
				{
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    return res; 
}
