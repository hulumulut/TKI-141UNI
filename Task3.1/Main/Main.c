#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>
#include <locale.h>
/*
* @brief Расчет функции в точке x
* @param x - введенная константа
* @return Значение функции
*/
double get_y(double x);

/**
* @brief Проверка на число
* @param message - текст сообщения для пользователя
* @return вовзращает значение
*/
double get_value(const char* message);

/*
* @brief Существует ли функция в точке x
* @param x - введенная константа
* @return true, если существует
*/
bool x_exist(double x);

/*
* @brief Точка входа в программу
* @return 0, в случае положительного результата
*/
int main() 
{
	setlocale(LC_ALL, "rus");
	double stx = get_value("Начальное значение x: ");
	double fnx = get_value("Конечное значение x: ");
	double step = get_value("Шаг для x: ");
	double x = stx;
	while (x - fnx <= DBL_EPSILON)
	{
		if (x_exist(x))
		{
			double y = get_y(x);
			printf_s("y = %lf, x = %lf\n", y, x);
		}
		else
		{
			printf_s("Решений нет при x = %lf\n", x);
		}
		x += step;
	}
	return 0;
}

bool x_exist(double x) 
{
	return x > DBL_EPSILON;
}

double get_y(double x) 
{
	return (3 * sin(sqrt(x))) + (0.39 * x) - 3.8;
}

double get_value(const char* message)
{
	double a;
	printf("%s", message);
	int res = scanf_s("%lf", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("Неправильное значение");
		abort();
	}
	return a;
}