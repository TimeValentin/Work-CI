#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

/*
	Написать программу вычисления максимального числа 
	из введенных пользователем в виде одной строки.  
	Использовать для этого макрос (без функции), 
	на вход которому подается массив чисел и их количество.
*/

#define FIND_MAX(arr, n) ({   \
long long max = (arr)[0]; \     
int i;                   \
for (i = 1; i < (n); i++) \
if ((arr)[i] > max)   \
    max = (arr)[i];    \
max;                    \ 
}) \

#define Sredney(arr, n) ({ \
long long sum = (arr)[0]; \
int i; \
for (i = 1; i < (n); i++) \
sum += (arr)[i]; \
(int)(sum/(n)); })  \


int main() 
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    char line[100];
    long long nums[100];
    int n = 0;
    printf ("Vvod sifr: ");
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \n");
    while (token != NULL) 
	{
        nums[n] = atoll(token);
        n++;
        token = strtok(NULL, " \n");
    }
    long long maxim = FIND_MAX(nums, n);
	int arefmet = Sredney(nums, n);
    printf("Максимальная and srednee arefmetichescoe цифра-число: %lld %d\n", maxim, arefmet);
    return 0;
}
