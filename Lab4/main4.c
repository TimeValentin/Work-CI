#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

extern double getPerimeter(double a, double b, double c);
extern double getArea(double a, double b, double c);

int main() {
	double a, b, c;

    /*setlocale(LC_ALL, "Rus");*/
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);
	printf("Ввести данные сторон a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) 
	{
     printf("Ошибка1 ТОЛЬКО ЦИФРЫ! \n");
     return 0;
    }

    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) 
	{
     printf("Периметр: %.2f\n", getPerimeter(a, b, c));
     printf("Площадь: %.2f\n", getArea(a, b, c));
    } 
	else 
	{
     printf("Ошибка2 таких сторон нет \n");
    }
	return 0;
}
