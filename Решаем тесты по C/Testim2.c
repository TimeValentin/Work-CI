#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k;
    int **matrix;
    FILE *file;
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    // Ввод размеров матрицы
    printf("Введите количество строк (n): ");
    scanf("%d", &n);
    printf("Введите количество столбцов (m): ");
    scanf("%d", &m);
    
    // Проверка на квадратную матрицу для диагоналей
    if (n != m) {
        printf("Ошибка: Для вычисления суммы главной и побочной диагоналей матрица должна быть квадратной!\n");
        return 1;
    }
    
    // Выделение памяти под матрицу
    matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти для строки %d!\n", i);
            // Освобождение уже выделенной памяти
            for (k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }
    
    // Заполнение матрицы случайными числами от 0 до 99
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    // Вывод матрицы на экран
    printf("\nСгенерированная матрица:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Запись матрицы в файл с помощью fprintf
    file = fopen("matrix.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        // Освобождение памяти
        for (i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }
    
    // Запись размеров матрицы
    fprintf(file, "%d %d\n", n, m);
    
    // Запись элементов матрицы
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    printf("\nМатрица успешно записана в файл 'matrix.txt'\n");
    
    // Чтение матрицы из файла
    file = fopen("matrix.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла для чтения!\n");
        // Освобождение памяти
        for (i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }
    
    // Создаём новую матрицу для чтения
    int **read_matrix;
    int read_n, read_m;
    
    // Чтение размеров
    fscanf(file, "%d %d", &read_n, &read_m);
    
    // Проверка соответствия размеров
    if (read_n != n || read_m != m) {
        printf("Ошибка: Размеры в файле не соответствуют исходной матрице!\n");
        fclose(file);
        // Освобождение памяти
        for (i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }
    
    // Выделение памяти под читаемую матрицу
    read_matrix = (int **)malloc(read_n * sizeof(int *));
    for (i = 0; i < read_n; i++) {
        read_matrix[i] = (int *)malloc(read_m * sizeof(int));
    }
    
    // Чтение элементов матрицы
    for (i = 0; i < read_n; i++) {
        for (j = 0; j < read_m; j++) {
            fscanf(file, "%d", &read_matrix[i][j]);
        }
    }
    
    fclose(file);
    printf("\nМатрица успешно прочитана из файла:\n");
    
    // Вывод прочитанной матрицы
    for (i = 0; i < read_n; i++) {
        for (j = 0; j < read_m; j++) {
            printf("%4d", read_matrix[i][j]);
        }
        printf("\n");
    }
    
    // Вычисление суммы главной и побочной диагоналей
    int main_diag_sum = 0;
    int secondary_diag_sum = 0;
    
    for (i = 0; i < n; i++) {
        main_diag_sum += read_matrix[i][i];           // Главная диагональ
        secondary_diag_sum += read_matrix[i][n - 1 - i]; // Побочная диагональ
    }
    
    printf("\nРезультаты вычислений:\n");
    printf("Сумма элементов главной диагонали: %d\n", main_diag_sum);
    printf("Сумма элементов побочной диагонали: %d\n", secondary_diag_sum);
    printf("Общая сумма: %d\n", main_diag_sum + secondary_diag_sum);
    
    // Форматированный вывод с sprintf в строку
    char buffer[256];
    sprintf(buffer, "Главная: %d, Побочная: %d, Всего: %d", 
            main_diag_sum, secondary_diag_sum, main_diag_sum + secondary_diag_sum);
    printf("\nФорматированная строка результата:\n%s\n", buffer);
    
    // Освобождение памяти
    for (i = 0; i < n; i++) {
        free(matrix[i]);
        free(read_matrix[i]);
    }
    free(matrix);
    free(read_matrix);
    
    printf("\nПамять успешно освобождена.\n");
    
    return 0;
}
