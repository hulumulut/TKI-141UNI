#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "Russian");
    // Ввод радиуса шара с условием
    double radius;
    printf_s("Введите радиус шара(положительный и больше 0): ");
    scanf_s("%lf", &radius);
    if (radius <= 0.0)
    { 
        printf_s("Некорректные данные");
    return 0;
    }

    // Выбор поиска
    int choice;
    printf_s("Выберите что хотите найти (1 - объем, 2 - площадь поверхности): ");
    scanf_s("%d", &choice);

    // Итог
    if (choice == 1) 
    {
        // Объем шара
        double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
        printf_s("Объем шара: %lf\n", volume);
    }
    else if (choice == 2) 
    {
        // Площадь поверхности шара
        double area = 4.0 * M_PI * pow(radius, 2);
        printf_s("Площадь поверхности шара: %lf\n", area);
    }
    else 
    {
        // В случае некорректного выбора формулы
        printf_s("Некорректный выбор формулы.\n");
        return 1;
    }

    return 0;
}