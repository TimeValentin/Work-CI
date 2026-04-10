#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
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
    printf("(+, -, *, / ): ");
    scanf(" %c", &znak);
	
    double **result = NULL;
    if (znak == '+') result = summ(a, b, x);
    else if (znak == '-') result = sub(a, b, x);
    else if (znak == '*') result = mult(a, b, x);
    else if (znak == '/') result = delenye(a, b, x);

    printf("\nResult\n");
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            printf("%g ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < x; i++) free(a[i]);
    free(a);   
    for (i = 0; i < x; i++) free(b[i]);
    free(b);
    for (i = 0; i < x; i++) free(result[i]);
    free(result);
    
    return 0;
}
