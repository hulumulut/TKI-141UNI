#include <stdio.h>
#include <locale.h>

// Функция для ввода положительного числа
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

// Функция для вычисления длины второй стороны
float B(float a, float n) 
{
    return n * a;
}

// Функция для вычисления периметра
float Perimeter(float a, float b) 
{
    return 2 * (a + b);
}

// Функция для вычисления площади
float Area(float a, float b) 
{
    return a * b;
}

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