#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Определение перечислимого типа для условий
enum Condition {
    CONDITION_1,
    CONDITION_2
};

int main() {
    // Значение a (заодно установка языка)
    setlocale(LC_ALL, "Russian");
    int a = 2.5;

    // Ввод значение X
    double x;
    printf_s("Введите значение X: ");
    scanf_s("%lf", &x);

    // Определение условия
    enum Condition condition;
    if (x > a || x <= a) {
        if (x > a) {
            condition = CONDITION_1;
        }
        else {
            condition = CONDITION_2;
        }
    }

    // Решение разветвленного уравнения с использованием switch
    double y;
    switch (condition) {
    case CONDITION_1:
        y = x * pow(x - a, 1.0 / 3.0);
        printf("Значение y с 1ым условием: %lf\n", y);
        break;

    case CONDITION_2:
        y = x * sin(a * x);
        printf("Значение y с 2ым условием: %lf\n", y);
        break;

    default:
        printf("Некорректное условие\n");
        return 1;
    }

    return 0;
}