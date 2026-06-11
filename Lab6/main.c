#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double matrix[3][3]; 
	double m,n;
	int i,j; 
	for (i = 0; i < 3; i++) { 
    	for (j = 0; j < 3; j++) {
    		scanf("%lf", &matrix[i][j]);
    	}
    }
    for (i = 0; i < 3; i++) {
		sub_main += matrix[i][i];
    	sub_sec += matrix[i][2-i];
	}	
	printf("main diagonary= %lf\n", a);
	printf("secondary diagonary = %lf\n", b);
	
	
	double A[2][2];
	double B[2][2];
	double a,b,c,d;
	for (i = 0; i < 2; i++) { 
    	for (j = 0; j < 2; j++) {
    		scanf("%lf", &A[i][j]);
    	}
	}
	
	a = A[0][0];
    b = A[0][1];
    c = A[1][0];
    d = A[1][1];
    
    B[0][0] = a * a + b * c;
    B[0][1] = a * b + b * d;
    B[1][0] = a * c + c * d;
    B[1][1] = b * c + d * d;
    
	for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%.2lf\t", B[i][j]);
        }
        printf("\n");
    }
	return 0;
}
