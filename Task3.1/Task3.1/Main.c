#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функция для вычисления значения функции
double calculate_function(double x) 
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

int main() 
{
    setlocale(LC_ALL, "Russian"); 
    // Заданный интервал и шаг
    double x_1 = 2.0;
    double x_2 = 3.0;
    double delta = 0.1;   

    // Вывод заголовка таблицы
    printf("x\t|\ty\n");
    printf("--------------------\n");

    // Табулирование функции 
    for (double x = x_1; x <= x_2; x += delta) 
    {
        double result = calculate_function(x);

        // Проверка на возможность расчета, является ли число числом, а не буквами или бесконечностью
        if (!isnan(result) && !isinf(result)) 
        {
            printf("%.2lf\t|\t%.2lf\n", x, result);
        }
        else 
        {
            printf("%.2lf\t|\tНет решения\n", x);
        }
    }

    return 0;
}