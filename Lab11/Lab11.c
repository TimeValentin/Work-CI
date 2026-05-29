#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functionLab11.h"
#include <windows.h>

/*
	Создать в отдельном модуле функции 
	с переменным количеством аргументов, 
	которая вычисляет их 
	сумму, максимум, минимум, среднее арифметическое.
*/

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int count = 3; 
    int n1, n2, n3; 
    int a, b, c;
    double d;
    printf("Надо ввести числа");
    if (scanf("%d %d %d", &n1, &n2, &n3) != 3) 
	{
        return 1;
    }

 	a = sum(count, n1, n2, n3);
    b = (max)(count, n1, n2, n3);
    c = (min)(count, n1, n2, n3);
    d = (average)(count, n1, n2, n3);

    printf("Результат %d %d %d %.2lf\n", a, b, c, d);
    return 0;
}






/*int main()
{
	int count = 3;
	int a = sum(count, 1, 2, 3);
	int b = max(count, 1, 2, 3);
	int c = min(count, 1, 2, 3);
	double d = average(count, 1, 2, 3);
	printf("%d %d %d %.2lf", a, b, c, d);
	return 0;
}
*/
