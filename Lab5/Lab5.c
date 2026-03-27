#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double* allocateMatrix(int n);
double* calculateMatrix(double* A, double* B, int n, char op);

void printMatrix(double* M, int n) 
{
    for ( i = 0; i < n; i++) 
	{
        for ( j = 0; j < n; j++) 
		printf("%.2f\t", M[i * n + j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) 
{
	int n;
    char op;

    printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    double *A = allocateMatrix(n);
    double *B = allocateMatrix(n);

    printf("Элементы матрицы A:\n");
    for (i = 0; i < n * n; i++) 
	scanf("%lf", &A[i]);

    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &op); 

    printf("Элементы матрицы B:\n");
    for ( i = 0; i < n * n; i++) 
	scanf("%lf", &B[i]);

    double* result = calculateMatrix(A, B, n, op);

    if (result) 
	{
        printf("Результат:\n");
        printMatrix(result, n);
        free(result);
    }
    free(A);
    free(B);
	
	return 0;
}




#include <stdio.h>
#include <stdlib.h> // Библиотека для работы с malloc и free

// Функция для выделения памяти под матрицу n x n
double** allocate_matrix(int n) {
    // 1. Выделяем массив указателей на строки
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        // 2. Для каждой строки выделяем массив элементов double
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

// Функция для освобождения памяти
void free_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;
    char op;

    // 1. Ввод размерности
    printf("Введите размерность матриц n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка: неверный размер.\n");
        return 1;
    }

    // 2. Динамическое выделение памяти для трех матриц (A, B и Результат)
    double** A = allocate_matrix(n);
    double** B = allocate_matrix(n);
    double** C = allocate_matrix(n);

    // 3. Ввод элементов матрицы A
    printf("Введите элементы матрицы A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // 4. Ввод элементов матрицы B
    printf("Введите элементы матрицы B (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &B[i][j]);
        }
    }

    // 5. Ввод знака операции
    printf("Введите операцию (+, -, *): ");
    // Пробел перед %c нужен, чтобы пропустить символ новой строки \n после ввода чисел
    scanf(" %c", &op);

    // 6. Выполнение операции
    if (op == '+') {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
    } 
    else if (op == '-') {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
    } 
    else if (op == '*') {
        // Умножение матриц (строка на столбец)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    } 
    else {
        printf("Ошибка: неизвестная операция '%c'.\n", op);
        // Освобождаем память перед выходом
        free_matrix(A, n); free_matrix(B, n); free_matrix(C, n);
        return 1;
    }

    // 7. Вывод результата
    printf("\nРезультат операции '%c':\n", op);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2f ", C[i][j]);
        }
        printf("\n");
    }

    // 8. Обязательное освобождение динамической памяти!
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}
