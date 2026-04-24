#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

/* Объявить тип-структуру humen,
 включающую имя человека, фамилию и год рождения. 
 Объявить два массива из четырёх элементов типа humen.? 
 Ввести с консоли или из фай-ла элементы одного массива 
 и построить на их основе другой, 
 упорядочив элементы по годам рождения. Вывести результат.
*/


struct human 
{
	char name[50];
	char surname[50];
	int year ;
};


int main() 
{
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "Rus");
    struct human source[4];
    struct human sorted[4];
    int i, j;
    int choice;
    
   printf("Выберите варианта ввода (1 - консоль, 2 - файл ЭНАДО ПРИДУМАТЬ СВОЙ ФАЛ НЕ ЗАБЫТЬЭ.txt): ");
    scanf("%d", &choice);

    if (choice == 2) 
	{
        FILE *file = fopen("input.txt", "r");
        if (file == NULL) 
		{
            printf("Ошибка Где файла!\n");
            return 1;
        }
        for (i = 0; i < 4; i++) 
		{
            fscanf(file, "%s %s %d", source[i].name, source[i].surname, &source[i].year);
        }
        fclose(file);
    } 
    
	else 
	{
        printf("Введите Имя, Фамилию и Год рождения 4 Humana:\n");
        for (i = 0; i < 4; i++) 
		{
            printf("Человек %d: ", i + 1);
            scanf("%s %s %d", source[i].name, source[i].surname, &source[i].year);
        }
    }

    for (i = 0; i < 4; i++) 
	{
        sorted[i] = source[i];
    }

    for (i = 0; i < 4 - 1; i++) 
	{
        for (j = 0; j < 4 - i - 1; j++) 
		{
            if (sorted[j].year > sorted[j + 1].year) 
			{
                struct human temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    printf("\n---+++Результат+++---\n");
    for (i = 0; i < 4; i++) 
	{
        printf("%d: %s %s\n", sorted[i].year, sorted[i].name, sorted[i].surname);
    }

    return 0;
} 
    
    /*FILE *file = fopen("Надо будет создать и написать.txt", "r");
    if (file == NULL) 
	{
        return 0;
    }
    
    setlocale(LC_ALL, "Rus");
    printf("Введите данные (Имя Фамилия Год):\n");
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
    printf("\n Отсортированный список (по году рождения):\n");
    for (i = 0; i < 4; i++) 
	{
	setlocale(LC_ALL, "Rus");
    printf("%d. %-5s. %-5s. — %d год\n", i + 1, sorted[i].name, sorted[i].surname, sorted[i].year);
    }
    return 0;
}*/
