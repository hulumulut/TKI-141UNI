#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

double get_volume(double radius);
double get_area(double radius);

int main()
{
    setlocale(LC_ALL, "Russian");
    double radius;
    int choice();
    printf_s("Введите радиус шара(положительный и больше 0): ");
    scanf_s("%lf", &radius);
    if (radius <= 0.0)
    {
        printf_s("Некорректные данные");
        return 0;
    }
    printf_s("площадь равна: %lf\n",get_area(radius));
    printf_s("объем равен: %lf\n", get_volume(radius));
}

    int choice ()
{
    printf("Выберите что хотите найти (1 - объем, 2 - площадь поверхности): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        double get_volume(double radius);
        return 0;
    }
    else if (choice == 2)
    {
        double get_area(double radius);
        return 0;
    }
    else
    {
        printf_s("Некорректный выбор формулы.\n");
        return 1;
    }

    return 0;
}

double get_volume(double radius) {
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    return volume;
}

double get_area(double radius) {
    double area = 4.0 * M_PI * pow(radius, 2);
    return area;
}