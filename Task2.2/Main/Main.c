#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() 
{
	// Значение a (заодно установка языка)
	setlocale(LC_ALL, "Russian");
	int a = 2.5;

	// Ввод значение X
	double x;
	printf_s("введите значение X:");
	scanf_s("%lf", &x);

	// Решение разветленного уравнения
	if (x > a || x <= a)
	{
		if (x > a) // первое решение, если значение x больше a
		{
			double y = x * pow(x - a, 1.0 / 3.0);
			printf("Значение y равно с 1ым условием: %fl\n", y);
		}
		else if (x <= a) // второе решение, если значение x меньше или равно a
		{
			double y = x * sin(a * x);
			printf("Значение y равно c 2ым условием: %fl\n", y);
		}
	}
	return 0;
}