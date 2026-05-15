#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include <wchar.h>

/* ќбъ€вить тип-структуру humen,
 включающую им€ человека, фамилию и год рождени€. 
 ќбъ€вить два массива из четырЄх элементов типа humen.? 
 ¬вести с консоли или из фай-ла элементы одного массива 
 и построить на их основе другой, 
 упор€дочив элементы по годам рождени€. ¬ывести результат.
*/
//1 узнать сколько людей
//2 выделить памети от размеера людей
//3 заполнить даннымилюдей


struct human 
{
    char name[50];
    char surname[50];
    int year;
};

int main() 
{
    setlocale(LC_ALL, "Rus");
    struct human *source = NULL;
    struct human *sorted = NULL;
    int i, j;
    int choice;
    int count = 0;
    
    printf("???????? ??????? ????? (1 - ???????, 2 - name.txt): ");
    if (scanf("%d", &choice) != 1) {
        return 0; // ?????????? 0, ???? ???? ???????????
    }

    if (choice == 2) 
    {
        FILE *file = fopen("name.txt", "r");
        if (file == NULL) 
        {
            printf("?????? ???????? ????? name.txt!\n");
            return 0; 
        }
        

        struct human temp;
        while (fscanf(file, "%49s %49s %d", temp.name, temp.surname, &temp.year) == 3)
        {
            count++;
        }
        
        printf("\n[????] ???????? ?????????? ????? (int): %d\n", count);

        if (count == 0) 
        {
            fclose(file);
            return 0;
        }

        // 2. ????????? ??????
        source = (struct human *)
		malloc(count * sizeof(struct human));
        sorted = (struct human *)
		malloc(count * sizeof(struct human));
        
        if (source == NULL || sorted == NULL) 
        {
            if (file) fclose(file);
            return 0;
        }

        rewind(file);

        for (i = 0; i < count; i++) 
        {
            fscanf(file, "%49s %49s %d", source[i].name, source[i].surname, &source[i].year);
        }
        fclose(file);
    } 
    else if (choice == 1) 
    {
        printf("??????? ?????????? ?????: ");
        if (scanf("%d", &count) != 1 || count <= 0) 
        {
            return 0;
        }

        source = (struct human *)
		malloc(count * sizeof(struct human));
        sorted = (struct human *)
		malloc(count * sizeof(struct human));
        
        if (source == NULL || sorted == NULL) {
            return 0;
        }

        printf("??????? ???, ??????? ? ??? ???????? ??? %d ???????:\n", count);
        for (i = 0; i < count; i++) 
        {
            printf("??????? %d: ", i + 1);
            scanf("%49s %49s %d", source[i].name, source[i].surname, &source[i].year);
        }
    }
    else 
    {
        return 0;
    }


    for (i = 0; i < count; i++) 
    {
        sorted[i] = source[i];
    }


    for (i = 0; i < count - 1; i++) 
    {
        for (j = 0; j < count - i - 1; j++) 
        {
            if (sorted[j].year > sorted[j + 1].year) 
            {
                struct human temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    printf("\n---+++????????? (????????????? ?? ?????)+++---\n");
    for (i = 0; i < count; i++) 
    {
        printf("%d: %s %s\n", sorted[i].year, sorted[i].name, sorted[i].surname);
    }

    free(source);
    free(sorted);

    return count; 
}
