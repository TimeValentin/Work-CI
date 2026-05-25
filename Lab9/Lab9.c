#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
Реализовать программу-калькулятор с 
возможностью выполнения арифметических действий (+, -), 
унарный и бинарный вариант. 

У пользователя запрашивается выраже-ние, например, 
"-123.5 + 4 - 456+56", программа должна решить выражение. 

Для разбо-ра входной строки использовать функцию strtok.
*/

int main() 
{
	setlocale(LC_ALL, "Rus");
    char buffer[100];
    int j = 0;
    int i;
    char *token; 
    
    printf("Введите ваше выражение: ");
    if (fgets(buffer, 100, stdin) == NULL) 
	{
        return 1;
    }
    
    buffer[strcspn(buffer, "\n")] = '\0';
    
    char result[100];
    for (i = 0; i < (int)strlen(buffer); i++) 
    {
        if (buffer[i] != ' ') 
        {
            result[j] = buffer[i];
            j++;
        }
    }
    result[j] = '\0';
    
    char result2[100];
    j = 0;
    for (i = 0; result[i] != '\0'; i++) 
    {
        if (result[i] == '-' && result[i + 1] == '-') 
        {
            result2[j] = '+';
            j++;
            i++;
        }
        else if (result[i] == '+' && result[i + 1] == '-') 
        {
            result2[j] = '-';
            j++;
            i++;
        }
        else 
        {
            result2[j] = result[i];
            j++;
        }
    }
    result2[j] = '\0';
    
    char result3[100];
    if (result2[0] == '-') 
    {
        snprintf(result3, sizeof(result3), "0%s", result2);
    }
    else 
    {
        snprintf(result3, sizeof(result3), "%s", result2);
    }
    
    char result4[1000];
    j = 0;
    for (i = 0; result3[i] != '\0'; i++) 
    {
        if (result3[i] == '-' 
		|| result3[i] == '+' 
		|| result3[i] == '*' 
		|| result3[i] == '/') 
        {
            result4[j++] = ' ';
            result4[j++] = result3[i];
            result4[j++] = ' ';
        }
        else 
        {
            result4[j] = result3[i];
            j++;
        }
    }
    result4[j] = '\0';


    double total = 0;
    double current_term = 0;
    char op = '+';
    char prev_op = '+';
    token = strtok(result4, " ");
    while (token != NULL) 
    {
        if (strlen(token) == 1 && 
           (token[0] == '+' 
		   || token[0] == '-' 
		   || token[0] == '*' 
		   || token[0] == '/')) 
        {
            op = token[0];
        } 
        else 
        {
            double num = atof(token);
            
            if (op == '*') 
            {
                current_term *= num;
            } 
            else if (op == '/') 
            {
                if (num != 0) 
                {
                    current_term /= num;
                } 
                else 
                {
                    printf("Деление на ноль нельзя!\n");
                    return 1;
                }
            } 
            else 
            {
                if (prev_op == '+') 
                {
                    total += current_term;
                } 
                else if (prev_op == '-') 
                {
                    total -= current_term;
                }
                current_term = num; 
                prev_op = op;       
            }
        }
        token = strtok(NULL, " ");
    }
    

    if (prev_op == '+') 
    {
        total += current_term;
    } 
    else if (prev_op == '-') 
    {
        total -= current_term;
    }
    
    printf("Результат: %.2f\n", total);
    
    return 0;
}



