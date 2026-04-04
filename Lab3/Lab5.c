#include <stdio.h>
#include <stdlib.h>
#include "Lab5_title.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i, j, k;
void printMatrix(double* M, int n) 
{
    for ( i = 0; i < n; i++) 
	{
        for ( j = 0; j < n; j++) 
		printf("%.2f\t", M[i * n + j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) 
{
	int n;
    char op;

  printf("Размерность матриц n: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
	{
        printf("Ошибка размер.\n");
        return 0;
    }

    double** A = allocate_matrix (n);
    double** B = allocate_matrix (n);
    double** C = allocate_matrix (n);

    printf("Матрица A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            scanf("%lf", &A[i][j]);
        }
    }

    printf("матрица В (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            scanf("%lf", &B[i][j]);
        }
    }

    printf("Введите (+, -, *): ");
    scanf(" %c", &op);

    if (op == '+') 
	{
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
    } 
    else if (op == '-') 
	{
        for ( i = 0; i < n; i++)
            for ( j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
    } 
    else if (op == '*') 
	{
        for (i = 0; i < n; i++) 
		{
            for (j = 0; j < n; j++) 
			{
                C[i][j] = 0;
                for (k = 0; k < n; k++) 
				{
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    } 
    else 
	{
        printf("Ошибка: '%c'.\n", op);
        free_matrix(A, n); free_matrix(B, n); free_matrix(C, n);
        return 1;
    }

    printf("Результат '%c':\n", op);
    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            printf("%8.2f ", C[i][j]);
        }
        printf("\n");
    }
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}
    /*printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    double *A = allocateMatrix(n);
    double *B = allocateMatrix(n);

    printf("Элементы матрицы A:\n");
    for (i = 0; i < n * n; i++) 
	scanf("%lf", &A[i]);

    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &op); 

    printf("Элементы матрицы B:\n");
    for ( i = 0; i < n * n; i++) 
	scanf("%lf", &B[i]);

    double* result = calculateMatrix(A, B, n, op);

    if (result) 
	{
        printf("Результат:\n");
        printMatrix(result, n);
        free(result);
    }
    free(A);
    free(B);
	
	return 0;
}*/







