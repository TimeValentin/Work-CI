#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* 
Создать текстовый файл с записями, 
включающие имя/фамилию человека, 
год рожде-ния, пол и рост (в метрах). 

Упорядочить элементы по году рождения, 
имени/фамилии, полу или росту. 

Вывести результат. Указать элемент, 
по которому следует упорядо-чить, через консоль. 
А также реализовать возможность 
задавать несколько полей для упорядочивания.
*/

struct humen
{
	char name[25];
	char lastname[25];
	int years;
	char pol[5];
	float rost;
};

int main(int argc, char *argv[]) 
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	int i = 0, j = 0, f = 0;
	int qwer;
	int num_fields;
	int fields[10];
	
	int lines = 0;
	char ch;
	
	printf("Выбор номера 1 - 4: ");
	scanf("%d", &num_fields);
	
	for(i = 0; i < num_fields; i++)
	{
		printf("Народ (1-Годочки, 2-Имя, 3-Рост, 4-ПолГендер): ");
		scanf("%d", &fields[i]);
	}
	
	FILE *file;
	
	file = fopen("name.txt","r");
	if(file == NULL)
	{
		printf("Ошибка!1.");
		return 1;
	}
	
	while((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n') 
		lines++;
	}
	
	lines++;
	n = lines;
	
	rewind(file);
	
	struct humen *arr1 = malloc(n * sizeof(struct humen));
	struct humen *arr2 = malloc(n * sizeof(struct humen));
	struct humen temp;
    
	for (i = 0; i < n; i++)
	{
		fscanf(file, "%s %s %d %s %f", 
		arr1[i].lastname, 
		arr1[i].name,
		&arr1[i].years, 
		arr1[i].pol, 
		&arr1[i].rost);
	}
	
	fclose(file);
	
	memcpy(arr2, arr1,n * sizeof(struct humen)); 
	
	printf("Сортировка по дате:\n");
	for (i = 0; i < n; i++)
	{
		printf("Фамилия/Имя: %s %s, Годочки: %d. Пол: %s. Рост: %.2f\n",
		arr1[i].name, 
		arr1[i].lastname,
		arr1[i].years, 
		arr1[i].pol, 
		arr1[i].rost);
	}
	
	for (i = 0; i < n - 1; i++)
	{
       	for (j = 0; j < n - 1 - i; j++)
		   {
       		
       		for(f = 0; f <num_fields; f++)
			   {	
				   switch (fields[f])
				   {
       					case 1:
							if (arr2[j].years > arr2[j + 1].years)
							{
	            				temp = arr2[j];
	               				arr2[j] = arr2[j + 1];
	               				arr2[j + 1] = temp;
					};
					break;
				
				case 2:
					if(strcmp(arr2[j].name, arr2[j + 1].name) > 0)
					{
           				temp = arr2[j];
               			arr2[j] = arr2[j + 1];
               			arr2[j + 1] = temp;
					};
					break;
					
				case 3:
					if(arr2[j].rost > arr2[j + 1].rost)
					{
            			temp = arr2[j];
               			arr2[j] = arr2[j + 1];
               			arr2[j + 1] = temp;
					};
					break;
					
				case 4:
					if(strcmp(arr2[j].pol, arr2[j + 1].pol) > 0)
					{
           				temp = arr2[j];
               			arr2[j] = arr2[j + 1];
               			arr2[j + 1] = temp;
					};
					break;
					
				
				default: printf("idofjhxdbvxf");
					return 1;
					break; 
			   }
		}
	}
}
       		
       		
	
    printf("\Ввывод гсортировки по выбору 2:\n");
	for (i = 0; i < n; i++)
	{
		printf("Фамилия/Имя: %s %s, Годочки: %d. Пол: %s. Рост: %.2f\n",
		arr2[i].name, 
		arr2[i].lastname,
		arr2[i].years,
		arr2[i].pol,
		arr2[i].rost);
	}
	
	return 0;
}
