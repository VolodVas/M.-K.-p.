#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція для введення елементів масиву
void inputArray(double *array, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Введіть елемент масиву a[%d]: ", i + 1);
        while (scanf("%lf", &array[i]) != 1) {
            printf("Некоректне введення. Введіть дійсне число для a[%d]: ", i + 1);
            while (getchar() != '\n'); // Очищення буфера вводу
        }
    }
}

// Функція для виведення елементів масиву
void printArray(double *array, int n) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < n; ++i) {
        printf("a[%d] = %.2lf\n", i + 1, array[i]);
    }
}

// Функція для обчислення суми модулів елементів масиву
double sumOfAbsoluteValues(double *array, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += fabs(array[i]);
    }
    return sum;
}

int main() {
    int continueProgram;

    do {
        int n;
        printf("Введіть кількість елементів масиву (натуральне число n): ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректне введення. Введіть натуральне число: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        double array[n];

        inputArray(array, n);
        printArray(array, n);

        double result = sumOfAbsoluteValues(array, n);
        printf("Сума модулів елементів масиву: %.2lf\n", result);

        // Меню для продовження або завершення програми
        printf("Продовжити? (Так, введіть 1) (Ні, введіть 0): ");
        while (scanf("%d", &continueProgram) != 1 || (continueProgram != 0 && continueProgram != 1)) {
            printf("Некоректне введення. Введіть 1 для продовження або 0 для завершення: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

    } while (continueProgram == 1);

    printf("Програму завершено.\n");

    return 0;
}
