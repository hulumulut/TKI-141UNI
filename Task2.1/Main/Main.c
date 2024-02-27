#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <errno.h>
/**
* @brief Пользовательский ввод
*/
enum area_or_volume {
    /**
    * @brief площадь
    */
    area = 1,
    /**
    * @brief объем
    */
    volume = 2
};

/**
* @brief ищет объем
* @param radius - заданный пользователем радиус
* @return возвращает значение объема
*/
double get_volume(double radius);

/**
* @brief ищет площадь
* @param radius - заданный пользователем радиус
* @return возвращает значение площади
*/
double get_area(double radius);

/**
* @brief проверка, что пользователь ввел число(его выбор)
* @remarks завершает программу ошибкой, если вводимое значение не число
* @return число(выбор)
*/
int get_choice();

/**
* @brief проверка, что пользователь ввел число
* @remarks завершает программу ошибкой, если вводимое значение не число
* @return значение
*/
double get_value();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает верно
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    puts("Введите радиус шара(положительный и больше 0): ");
    double radius;
    radius = get_value();
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
        default:
        {
            errno = EIO;
            perror("Ошибка ввода");
            return 1;
        }
    }
    return 0;
}

double get_value()
{
    double a;
    int res = scanf_s("%lf", &a);
    if (res <= 0.0 || a <= 0.0)
    {
        errno = EIO;
        perror("Некорректные данные");
        abort();
    }
    return a;
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
