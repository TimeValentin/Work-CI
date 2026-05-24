#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Объявить тип-структуру humen,
 включающую имя человека, фамилию и год рождения. 
 Объявить два массива из четырёх элементов типа humen.? 
 Ввести с консоли или из фай-ла элементы одного массива 
 и построить на их основе другой, 
 упорядочив элементы по годам рождения. Вывести результат.
1 узнать сколько людей
2 выделить памети от размеера людей
3 заполнить даннымилюдей
*/

struct human 
{
    char name[50];
    char lastname[50];
    int year;
};

int main() 
{
    setlocale(LC_ALL, "Rus");
    struct human *arr_A = NULL;
    struct human *arr_B = NULL;
    int choice;
    int element = 0;
    int i, j;
 

    printf("Выберите (1 - Ввод с консоли, 2 - Файла name.txt): ");
    if (scanf("%d", &choice) != 1) 
	{
        printf("Ошибка\n");
        return 1; 
    }

    if (choice == 2) 
    {
        FILE *file = fopen("name.txt", "r");
        if (file == NULL) 
        {
            return 1; 
        }

        char ch;
        int lines_file = 0;
        while ((ch = fgetc(file)) != EOF) 
        {
            if (ch == '\n') 
			{
                lines_file++;
            }
        }
        if (ch != '\n' && lines_file > 0) 
		{
            lines_file++;
        }
        rewind(file);
        if (lines_file == 0) 
		{
            if (fgetc(file) != EOF) lines_file = 1;
            rewind(file);
        }

        if (lines_file == 0) 
		{
            fclose(file);
            return 0;
        }

        arr_A = (struct human *)
		malloc(lines_file * sizeof(struct human));
        arr_B = (struct human *)
		malloc(lines_file * sizeof(struct human));
        if (arr_A == NULL || arr_B == NULL) 
		{
            printf("Ошибка с памятью на всякий случай\n");
            fclose(file);
            return 1;
        }

        element = 0; 
        for (i = 0; i < lines_file; i++) 
        {
            if (fscanf(file, "%49s %49s %d", 
			arr_A[element].name, 
			arr_A[element].lastname, 
			&arr_A[element].year) == 3) 
            {
                element++; 
            }
        }
        fclose(file); 
        
        printf("Количество людей из файла: %d\n", element);
        
        if (element == 0) 
		{
            free(arr_A);
            free(arr_B);
            return 0;
        }
    }

    else if (choice == 1) 
    {
        printf("Ввести количество людей: ");
        if (scanf("%d", &element) != 1 || element <= 0) 
		{
            printf("Ошибка\n");
            return 1;
        }

        arr_A = (struct human *)
		malloc(element * sizeof(struct human));
        arr_B = (struct human *)
		malloc(element * sizeof(struct human));
        if (arr_A == NULL || arr_B == NULL) {
            printf("Ошибка!\n");
            return 1;
        }

        printf("\n-Ввод данных-\n");
        for (i = 0; i < element; i++) 
        {
            printf("Человек %d (Имя Фамилия Год): ", i + 1);
            scanf("%49s %49s %d", 
			arr_A[i].name, 
			arr_A[i].lastname, 
			&arr_A[i].year);
        }
    }
    else 
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    for (i = 0; i < element; i++) 
    {
        arr_B[i] = arr_A[i];
    }

    for (i = 0; i < element - 1; i++) 
    {
        for (j = 0; j < element - i - 1; j++) 
        {
            if (arr_B[j].year > arr_B[j + 1].year) 
            {
                struct human temp = arr_B[j];
                arr_B[j] = arr_B[j + 1];
                arr_B[j + 1] = temp;
            }
        }
    }

    printf("\n результат \n");
    for (i = 0; i < element; i++) 
    {
        printf("%d. %-15s %-15s Годики %-15d\n", 
		i+1, arr_B[i].name, 
		arr_B[i].lastname, 
		arr_B[i].year);
    }


    free(arr_A);
    free(arr_B);

    return 0; 
}

