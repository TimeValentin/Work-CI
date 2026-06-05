#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define Diskrimin(a, b, c) ((b)*(b) - 4*(a)*(c))

int main(int argc, char *argv[]) {
	
	int a = 2, b = 5, c = 1;
	int descrimin = Diskrimin(a, b, c);
	printf("Hallo world: %d \n", descrimin);
	return 0;
}
