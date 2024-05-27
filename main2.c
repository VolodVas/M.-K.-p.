#include <stdio.h>
#include <math.h>

// Функція для обчислення відстані між двома точками (в декартовій системі координат)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Функція для обчислення площі трикутника за відомими довжинами сторін (за формулою площі Герона)
double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Функція для перевірки чи може трикутник існувати за заданими сторонами
int isTriangleValid(double a, double b, double c) {
    return a + b > c && a + c > b && b + c > a;
}

// Функція для перевірки чи введене значення є дійсним числом
int isValidDouble(double num) {
    return num == (double)((int)num);
}

// Функція для введення координат вершин трикутника з перевіркою введених даних
void inputTriangle(double *x1, double *y1, double *x2, double *y2, double *x3, double *y3) {
    int validInput = 0;
    while (!validInput) {
        printf("Введіть координати вершин трикутника (x1 y1 x2 y2 x3 y3): ");
        if (scanf("%lf %lf %lf %lf %lf %lf", x1, y1, x2, y2, x3, y3) == 6) {
            if (isValidDouble(*x1) && isValidDouble(*y1) && isValidDouble(*x2) &&
                isValidDouble(*y2) && isValidDouble(*x3) && isValidDouble(*y3)) {
                double a = distance(*x1, *y1, *x2, *y2);
                double b = distance(*x2, *y2, *x3, *y3);
                double c = distance(*x3, *y3, *x1, *y1);
                if (isTriangleValid(a, b, c)) {
                    validInput = 1;
                } else {
                    printf("Трикутник з такими сторонами не існує. Будь ласка, спробуйте ще раз.\n");
                }
            } else {
                printf("Некоректні координати. Будь ласка, введіть дійсні числа.\n");
            }
        } else {
            printf("Некоректний ввід. Будь ласка, введіть шість координат вершин трикутника.\n");
            while (getchar() != '\n'); // Очищення буфера вводу
        }
    }
}

// Головна функція
int main() {
    int continueProgram = 1;

    do {
        double x1, y1, x2, y2, x3, y3;

        printf("Введіть координати вершин першого трикутника:\n");
        inputTriangle(&x1, &y1, &x2, &y2, &x3, &y3);

        double a1 = distance(x1, y1, x2, y2);
        double b1 = distance(x2, y2, x3, y3);
        double c1 = distance(x3, y3, x1, y1);

        printf("Введіть координати вершин другого трикутника:\n");
        inputTriangle(&x1, &y1, &x2, &y2, &x3, &y3);

        double a2 = distance(x1, y1, x2, y2);
        double b2 = distance(x2, y2, x3, y3);
        double c2 = distance(x3, y3, x1, y1);

        double area1 = triangleArea(a1, b1, c1);
        double area2 = triangleArea(a2, b2, c2);

        printf("Площа першого трикутника: %.2lf\n", area1);
        printf("Площа другого трикутника: %.2lf\n", area2);

        if (area1 > area2) {
            printf("Перший трикутник має більшу площу.\n");
        } else if (area2 > area1) {
            printf("Другий трикутник має більшу площу.\n");
        } else {
            printf("Площі обох трикутників рівні.\n");
        }

        printf("Бажаєте продовжити програму? (1 - так, 0 - ні): ");
        scanf("%d", &continueProgram);

    } while (continueProgram == 1);

    printf("Програма завершена.\n");

    return 0;
}
