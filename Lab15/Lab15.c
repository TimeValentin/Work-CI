#include <stdio.h>
#include <stdlib.h>

/* 
	ƒано натуральное число N. 
	¬ыведите все его цифры по одной, 
	в обычном пор€дке (а потом в обратном), 
	раздел€€ их пробелами или новыми строками. 
	Ќапример: 179 => 1 7 9; 179 => 9 7 1
	ѕри решении этой задачи нельз€ использовать строки, 
	списки, массивы (ну и циклы, разумеетс€).
*/

void print_forward(int n) 
{
    if (n < 2) 
	{
        printf("%d ", n);
        return;
    }
    print_forward(n / 10);
    printf("%d ", n % 10);
}

void print_backward(int n) 
{
    if (n < 2) 
	{
        printf("%d ", n);
        return;
    }
    printf("%d ", n % 10);
    print_backward(n / 10);
}

int main(int argc, char *argv[]) 
{
	int n;
    printf("enter: ");
    scanf("%d", &n);
    print_forward(n);
	printf("\n");
    print_backward(n);
	return 0;
}
