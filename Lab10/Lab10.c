#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FIND_MAX(arr, n) ({   \
long long max = (arr)[0]; \     
int i;                   \
for (i = 1; i < (n); i++) \
if ((arr)[i] > max)   \
    max = (arr)[i];    \
max;                    \ 
}) \

int main() 
{
	setlocale(LC_ALL, "Rus");
    char line[1000];
    long long nums[100];
    int n = 0;
    printf ("Напиши цифры/числа через пробел: ");
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    while (token != NULL) {
        nums[n] = atoll(token);
        n++;
        token = strtok(NULL, " ");
    }
    long long maximum = FIND_MAX(nums, n);
    printf("Максимальная цифра/число: %lld\n", maximum);
    return 0;
}
