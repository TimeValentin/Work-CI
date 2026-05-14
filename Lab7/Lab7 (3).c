#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include <wchar.h>

/* Объявить тип-структуру humen,
 включающую имя человека, фамилию и год рождения. 
 Объявить два массива из четырёх элементов типа humen.? 
 Ввести с консоли или из фай-ла элементы одного массива 
 и построить на их основе другой, 
 упорядочив элементы по годам рождения. Вывести результат.
*/
//1 узнать сколько людей
//2 выделить памети от размеера людей
//3 заполнить даннымилюдей

struct human 
{
	char name[50];
	char surname[50];
	int year ;
};


int main() 
{
	//system("chcp 65001 > nul");
	setlocale(LC_ALL, "Rus");
    struct human *source = NULL;
    struct human *sorted = NULL;
    int i, j;
    int choice;
    int count = 0;
    //char buff[100];
    
   printf("Выберите варианта ввода (1 - консоль, 2 - name.txt): ");
    scanf("%d", &choice);

    if (choice == 2) 
	{
        FILE *file = fopen("name.txt", "r");
        if (file == NULL) 
		{
            printf("Ошибка Где файла!\n");
            return 1;
        }
        
        struct human temp;
        while (fscanf(file, "%50s %50 %d", temp.name, temp.surname, &temp.year) ==3)
        {
        	count++;
		}
        
        if (count == 0) 
		{
            printf("name.txt.\n");
            fclose(file);
            return 1;
        }

        source = (struct human *)
		malloc(count * sizeof(struct human));
        sorted = (struct human *)
		malloc(count * sizeof(struct human));
        
        if (source == NULL || sorted == NULL) 
		{
            printf("Ошибка.\n");
            fclose(file);
            return 1;
        }

 		//Незабыть написать возращение
        rewind(file);


        for (i = 0; i < count; i++) 
        {
            fscanf(file, "%50s %50s %d", source[i].name, source[i].surname, &source[i].year);
        }
        fclose(file);
        printf("Все работает %d\n", count);
    } 
    else if (choice == 1) // Исправлена логика ветвления
    {
        printf("Введите количество людей: ");
        if (scanf("%d", &count) != 1 || count <= 0) 
        {
            printf("Некорректное количество.\n");
            return 1;
        }

        source = (struct human *)malloc(count * sizeof(struct human));
        sorted = (struct human *)malloc(count * sizeof(struct human));
        
        if (source == NULL || sorted == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }

        printf("Введите Имя, Фамилию и Год рождения для %d человек:\n", count);
        for (i = 0; i < count; i++) // Вместо жесткого лимита 4 теперь используется count
        {
            printf("Человек %d: ", i + 1);
            scanf("%49s %49s %d", source[i].name, source[i].surname, &source[i].year);
        }
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
