#include <stdlib.h>

double* allocateMatrix(int n) 
{
    return (double*)malloc(n*n*sizeof(double));
}

double* calculateMatrix(double* A, double* B, int n, char op) 
{
    double* res = allocateMatrix(n);
    if (!res) return NULL;

    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            int idx = i * n + j;
            if (op == '+') 
			{
                res[idx] = A[idx] + B[idx];
            } 
			else if (op == '-') 
			{
                res[idx] = A[idx] - B[idx];
            } 
			else if (op == '*') 
			{
                res[idx] = 0;
                for (int k = 0; k < n; k++) 
				{
                    res[idx] += A[i * n + k] * B[k * n + j];
                }
            }
        }
    }
    return res;
}



