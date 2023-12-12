#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

/**
* @brief функция для поиска x
* @return завершает функцию, выводя ответ
*/
double calculate_function(double x);

/**
* @brief функция, где присходит табуляция, а также вывод результата
* @param заданные пользователем аргументы x_1, x_2, delta
*/
void tabulate_and_print();

/**
* @brief основная функция, где присходит вызов к таблице
* @return завершение программы с выводом результата
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    // Вызов функции для табуляции и вывода результатов
    tabulate_and_print();

    return 0;
}

double calculate_function(double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

// Функция для табуляции функции и вывода результатов
void tabulate_and_print()
{
    // Заданный интервал и шаг, вводимые пользователем
    double x_1, x_2, delta;

    printf("Введите начальное значение x (x_1): ");
    if (scanf_s("%lf", &x_1) != 1) {
        printf("Ошибка!\n");
        return;
    }

    printf("Введите конечное значение x (x_2): ");
    if (scanf_s("%lf", &x_2) != 1) {
        printf("Ошибка!\n");
        return;
    }

    printf("Введите шаг (delta): ");
    if (scanf_s("%lf", &delta) != 1 || delta <= 0 || x_1 > x_2) {
        printf("Ошибка!\n");
        return;
    }

    // Вывод заголовка таблицы
    printf("x\t|\ty\n");
    printf("--------------------\n");

    for (double x = x_1; x <= x_2; x += delta)
    {
        double result = calculate_function(x);

        // Проверка на возможность расчета с использованием DBL_EPSILON
        if (!isnan(result) && !isinf(result))
        {
            printf("%.2lf\t|\t%.2lf\n", x, result);
        }
        else
        {
            printf("%.2lf\t|\tНет решения\n", x);
        }
    }
}
