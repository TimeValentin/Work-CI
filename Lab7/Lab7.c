#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* ќбъ€вить тип-структуру humen,
 включающую им€ человека, фамилию и год рождени€. 
 ќбъ€вить два массива из четырЄх элементов типа humen.? 
 ¬вести с консоли или из фай-ла элементы одного массива 
 и построить на их основе другой, 
 упор€дочив элементы по годам рождени€. ¬ывести результат.
*/


struct human 
{
	char name[50];
	char surname[50];
	int year ;
};

int main() 
{
	setlocale(LC_ALL, "Rus");
    struct human source[4];
    struct human sorted[4];
    int i, j;
    
    setlocale(LC_ALL, "Rus");
    printf("¬ведите данные (»м€ ‘амили€ √од):\n");
    for (i = 0; i < 4; i++) 
	{
    printf("%d: ", i + 1);
    scanf("%s %s %d", source[i].name, source[i].surname, &source[i].year);
    }

    for (i = 0; i < 4; i++) 
	{
    sorted[i] = source[i];
    }

    for (i = 0; i < 3; i++);
        for (j = 0; j < 3 - i; j++) 
		{
            if (sorted[j].year > sorted[j + 1].year) 
			{
            struct human temp = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp;
            }
        }

	setlocale(LC_ALL, "Rus");
    printf("\n ќтсортированный список (по году рождени€):\n");
    for (i = 0; i < 4; i++) 
	{
	setlocale(LC_ALL, "Rus");
    printf("%d. %-5s. %-5s. Ч %d год\n", i + 1, sorted[i].name, sorted[i].surname, sorted[i].year);
    }
    return 0;
}
