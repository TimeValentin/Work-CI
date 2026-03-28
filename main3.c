#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	
	char str[81];
	int i;
	
	SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);
	printf("Введите не более 80 символов: \n");
    
	if (fgets(str, sizeof(str), stdin)); 
	{      
        for (i = 0; str[i] != '\0'; i++) 
		{
            if (str[i] == 'a') 
			{
                str[i] = 'A';
            } 
			else if (str[i] == 'b') 
			{
                str[i] = 'B';
            }
        }
        
        SetConsoleCP(1251);       
        SetConsoleOutputCP(1251);
        printf("Вывод новой сторки: %s", str);
    }
	return 0;
}
