#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <float.h>

/**
* @brief используется для определения типа условия
* @param CONDITION_1 и 2 - параметр с определенным условием, решение зависит от пользователя
*/ 
enum Condition
{
    CONDITION_1,
    CONDITION_2
};

/**
* @brief условия получения y1 и y2
* @param числа, введенные пользователем и проверенные программой на корректность
*/
double get_y1(double x, double a);
double get_y2(double x, double a);

/**
* @brief основная функция в программе
* @param сравнение параметров и выбор подходящего к условию
* @return 0 программа завершается без ошибки
*/
int main() 
{
    // Значение a (заодно установка языка)
    setlocale(LC_ALL, "Russian");
    double a = 2.5;

    // Ввод значение X
    double x;
    printf("Введите значение X: ");
    if (scanf_s("%lf", &x) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    // Определение условия
    enum Condition condition;

    // Сравнение через DBL_EPSILON
    if (fabs(x - a) < DBL_EPSILON) 
    {
        condition = CONDITION_1;
    }
    else 
    {
        if (x > a) 
        {
            condition = CONDITION_1;
        }
        else {
            condition = CONDITION_2;
        }
    }

    // Решение разветвленного уравнения с использованием switch
    double y1;
    double y2;
    switch (condition) 
    {
    case CONDITION_1:
        y1 = get_y1( x, a);
        printf("Значение y с 1ым условием: %lf\n", y1);
        break;

    case CONDITION_2:
        y2 = get_y2( x,  a);
        printf("Значение y с 2ым условием: %lf\n", y2);
        break;

    default:
        printf("Некорректное условие\n");
        return 1;
    }

    return 0;
}




double get_y1(double x, double a)
{
    return (x * pow(x - a, 1.0 / 3.0));
}

double get_y2(double x, double a)
{
    return (x * sin(a * x));
}