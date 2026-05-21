#include <stdio.h>
#include <stdlib.h>
//#include <>

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

struct human {
    char name[50];       // Массив для имени
    char surname[50];    // Массив для фамилии
    int birth_year;      // Год рождения
};

// Функция-компаратор для сортировки по годам рождения
int compare_by_year(const void *a, const void *b) {
    struct human *personA = (struct human *)a;
    struct human *personB = (struct human *)b;
    return personA->birth_year - personB->birth_year;
}

int main() {
    // Настройка локали для корректного вывода кириллицы (для Windows)
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    // 2. Считаем количество строк в файле
    FILE *file = fopen("name.txt", "r");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл name.txt\n");
        return 1;
    }

    int lines_count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines_count++;
        }
    }
    // Добавляем последнюю строку, если файл не заканчивается на новую строку
    if (ch != '\n' && lines_count > 0) {
        lines_count++;
    }
    
    // Если файл пустой, но содержит текст без \n
    rewind(file); 
    if (lines_count == 0) {
        // Проверяем, есть ли вообще символы
        if (fgetc(file) != EOF) lines_count = 1;
        rewind(file);
    }

    printf("Количество строк (людей) в файле: %d\n", lines_count);

    // 3. Выделяем динамическую память под размер людей из файла
    struct human *array_from_file = (struct human *)malloc(lines_count * sizeof(struct human));
    if (array_from_file == NULL) {
        printf("Ошибка выделения памяти для первого массива!\n");
        fclose(file);
        return 1;
    }

    // 4. Заполняем первый массив данными из файла
    for (int i = 0; i < lines_count; i++) {
        if (fscanf(file, "%49s %49s %d", array_from_file[i].name, array_from_file[i].surname, &array_from_file[i].birth_year) != 3) {
            printf("Ошибка чтения данных из файла на строке %d\n", i + 1);
            free(array_from_file);
            fclose(file);
            return 1;
        }
    }
    fclose(file); // Закрываем файл, он больше не нужен

    // 5. Ввод элемента с консоли
    printf("\n--- Ввод нового человека с консоли ---\n");
    struct human console_person;
    printf("Введите имя: ");
    scanf("%49s", console_person.name);
    printf("Введите фамилию: ");
    scanf("%49s", console_person.surname);
    printf("Введите год рождения: ");
    scanf("%d", &console_person.birth_year);

    // 6. Строим второй массив на основе первого + элемент из консоли
    int second_array_size = lines_count + 1;
    struct human *second_array = (struct human *)malloc(second_array_size * sizeof(struct human));
    if (second_array == NULL) {
        printf("Ошибка выделения памяти для второго массива!\n");
        free(array_from_file);
        return 1;
    }

    // Копируем данные из файлового массива во второй массив
    for (int i = 0; i < lines_count; i++) {
        second_array[i] = array_from_file[i];
    }
    // Добавляем в конец элемент, считанный с консоли
    second_array[second_array_size - 1] = console_person;

    // Освобождаем память первого массива, он больше не нужен
    free(array_from_file);

    // 7. Упорядочиваем (сортируем) элементы по годам рождения
    qsort(second_array, second_array_size, sizeof(struct human), compare_by_year);

    // 8. Выводим результат
    printf("\n--- Итоговый упорядоченный список (Второй массив) ---\n");
    for (int i = 0; i < second_array_size; i++) {
        printf("%d. %s %s, Год рождения: %d\n", 
               i + 1, second_array[i].name, second_array[i].surname, second_array[i].birth_year);
    }

    // Освобождаем память второго массива перед выходом
    free(second_array);
    return 0;
}
