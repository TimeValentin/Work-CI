#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILNAME "name.txt"
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

typedef struct
{
	char name [256];
	char lastname[256];
	int year;
	char gender;
	float height;
} Person;

int num_poligon =0;
int i;

int compare_tabl (const void *a, const void *b)
{
	Person *p1 = (Person*)a;
	Person *p2 = (Person*)b;
	
	for (i = 0; i < num_poligon; i++) 
	{
    int res = 0;
    switch (priorities[i]) 
	{
        case 1: res = strcmp(p1->name, p2->name); 
		break;
        case 2: res = strcmp(p1->lastname, p2->lastname); 
		break;
        case 3: res = p1->year - p2->year; 
		break;
        case 4: res = strcmp(p1->gender, p2->gender); 
		break;
        case 5: res = (p1->height > p2->height) - (p1->height < p2->height); 
		break;
    }
    if (res != 0) return res; 
 } 
	return 0;
}




int main() 
{
	FILE *file = fopen("name.txt", "r");

	return 0;
}
