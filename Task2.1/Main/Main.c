#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
/**
* @brief Присваивает значения константам area и volume
*/
enum area_or_volume {
    area = 1,
    volume = 2
};

/**
* @brief ищет объем
* @param заданный пользователем радиус
* @return возвращает значение объема
*/
double get_volume(double radius);

/**
* @brief ищет площадь
* @param заданный пользователем радиус
* @return возвращает значение площади
*/
double get_area(double radius);

/**
* @brief проверка, что пользователь ввел число
* @return завершает программу ошибкой, если вводимое значение не число
*/
int get_choice();

/**
* @brief основная функция
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    double radius;
    printf_s("Введите радиус шара(положительный и больше 0): ");
    scanf_s("%lf", &radius);
    if (radius <= 0.0)
    {
        printf_s("Некорректные данные");
        return 0;
    }
    int number = get_choice();
    enum area_or_volume j = (enum area_or_volume)(number);
    switch (j) 
    {
        case area: 
        {
            double area = get_area(radius);
            printf_s("площадь равна: %lf\n", get_area(radius));
            break;
        }
        case volume: 
        {
            double volume = get_volume(radius);
            printf_s("объем равен: %lf\n", get_volume(radius));
            break;
        }
    }
    return 0;
}
    
int get_choice ()
{
    int choice;
    printf("%s\n", "Введите, что хотите найти, площадь или объем ");
    printf("Площадь - %d\n", (int)area);
    printf("Объем - %d\n", (int)volume);
    int result = scanf_s("%d", &choice);
    if (result != 1)
    {
        errno = EIO;
        perror("Ошибка ввода");
        abort();
    }
    return choice;
}

double get_volume(double radius) {
    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    return volume;
}

double get_area(double radius) {
    double area = 4.0 * M_PI * pow(radius, 2);
    return area;
}
