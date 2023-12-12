#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/**
* @brief ищем аргумент a
*/
void get_a(float x, float y, float z)
{
	float a = (2 * cos(x - M_PI / 6)) / ((1 / 2) + pow(sin(y), 2)); // Формула a
	printf_s("a=%f", a);
}
/**
* @brief ищем аргумент b
*/
void get_b(float x, float y, float z)
{
	float b = 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5)); // Формула b
	printf_s("b=%f", b);
}
/**
* @brief основная функция программа
* @param get_a - параметры x,y,z для поиска аргумента a
* @param get_b - параметры x,y,z для поиска аргумента b
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	get_a(1.426, -1.22, 3.5);
	get_b(1.426, -1.22, 3.5);
}