#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <locale.h> 

int main() 
{
	setlocale(LC_ALL, "Rus");
    int x, i, j, n, m;
	double **a, **b;
    printf("Matrix_size = ");
    if (scanf("%d", &x) != 1) return 1;
    
	a = locate_matrix (x);
	
	printf ("\nFirst_Matrix\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    
	b = locate_matrix (x);
	
    printf ("\nSecond_Matrix\n");
    for (n = 0; n < x; n++) {
        for (m = 0; m < x; m++) {
            printf("b[%d][%d] = ", n, m);
            scanf("%lf", &b[n][m]);
        }
    }

    char znak;
    printf("(+, -, *): ");
    scanf(" %c", &znak);
	
    double **result = NULL;
    if (znak == '+') result = summ(a, b, x);
    else if (znak == '-') result = sub(a, b, x);
    else if (znak == '*') result = mult(a, b, x);

    printf("\nResult\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("%g ", result[i][j]);
        }
        printf("\n");
    }

	char reset_choice;
    printf("Хотите очистить динамическую память? \ (y/n): \n");
    scanf(" %c", &reset_choice);

	if (reset_choice == 'y' || reset_choice == 'Y') 
	{

    for (i = 0; i < x; i++) free(a[i]);
    free(a);  
	printf("Matrix A: ");
 
    for (i = 0; i < x; i++) free(b[i]);
    free(b);
    printf("Matrix B: ");

    for (i = 0; i < x; i++) free(result[i]);
    free(result);
    printf("Result Matrix: ");

	printf("Memory has been cleared successfully.\n");
    } 
	
	else 
	{
        printf("Memory clearing skipped (OS will reclaim it on exit).\n");
    }

    
    return 0;
}
