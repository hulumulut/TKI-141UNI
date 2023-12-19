#include <stdio.h>
#include <locale.h>

/**
* @brief Функция для ввода положительного числа, с проверкой этого числа
* @param числа, заданные пользователем
* @return завершает функцию с выводом числа пользователя, проверенного программой
*/

float inputPositiveNumber(const char* prompt);

/**
* @brief Функция для вычисления длины второй стороны
* @param числа, заданные пользователем и проверенные программой
* @param число, которое находит программа путем заданного уравнения
* @return завершает функцию с выводом результата
*/ 

float B(float a, float n);

/**
* @brief Функция для вычисления периметра
* @param числа, заданные пользователем и проверенные программой
* @param число, которое находит программа путем заданного уравнения
* @return завершает функцию с выводом результата
*/ 

float Perimeter(float a, float b);

/**
* @brief Функция для вычисления площади
* @param числа, заданные пользователем и проверенные программой
* @param число, которое находит программа путем заданного уравнения
* @return завершает функцию с выводом результата
*/ 

float Area(float a, float b);

/**
* @brief основная функция в программе
* @param числа, заданные пользователем
* @param числа, найденные программой
* @return завершает программу с выводом данных
*/
int main() 
{
    setlocale(LC_ALL, "Russian");
    float a, n, b, perimeter, area;

    // Ввод данных пользователем
    a = inputPositiveNumber("Введите длину стороны (a): ");
    n = inputPositiveNumber("Введите коэффициент (n): ");

    // Вычисление длины второй стороны
    b = B(a, n);

    // Вычисление периметра и площади
    perimeter = Perimeter(a, b);
    area = Area(a, b);

    // Вывод результатов
    printf("Периметр прямоугольника: %.2f\n", perimeter);
    printf("Площадь прямоугольника: %.2f\n", area);

    return 0;
}



float inputPositiveNumber(const char* prompt)
{
    float number;
    printf_s(prompt);
    if (scanf_s("%f", &number) != 1 || number <= 0)
    {
        printf_s("Некорректное значение. Пожалуйста, введите положительное число.\n");
        return inputPositiveNumber(prompt);
    }
    return number;
}

float B(float a, float n)
{
    return n * a;
}

float Perimeter(float a, float b)
{
    return 2 * (a + b);
}

float Area(float a, float b)
{
    return a * b;
}