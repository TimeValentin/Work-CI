#include <stdio.h>
#include <locale.h>

/*   
  1. Создать текстовый файл с записями следующего вида:
Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
….
Воробьянинов Ипполит Матвеевич 1978

2.  Прочитать данные из этого файла 
   и записать в другой только те строки, 
   которые относятся к родившимся позднее 1980 года.

*/

int main() {
    FILE *fin, *fout;
    char *locale = setlocale(LC_ALL, "");
    char familyname[64], name[64], ochestvo[64];
    int year;

    fin = fopen("data.txt", "r");

    fout = fopen("result.txt", "w");

    while (fscanf(fin, "%63s %63s %63s %d", familyname, name, ochestvo, &year) == 4) {
        if (year >= 1980) {
            fprintf(fout, "%s %s %s %d\n", familyname, name, ochestvo, year);
        }
    }

    fclose(fin);
    fclose(fout);

    printf("data in result(Результат).txt\n");

    return 0;
}
