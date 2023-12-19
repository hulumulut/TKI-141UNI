#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/**
* @brief ищем аргумент a
* @param аргумент a, плюс заданное к нему уравнение
*/
float get_a(float x, float y, float z);

/**
* @brief ищем аргумент b
* @param аргумент b, плюс заданное к нему уравнение
*/
float get_b(float x, float y, float z);

/**
* @brief основная функция программа
* @param get_a - параметры x,y,z для поиска аргумента a
* @param get_b - параметры x,y,z для поиска аргумента b
*/
int main()
{
	const float x = 1.426;
	const float y = -1.22;
	const float z = 3.5;
	setlocale(LC_ALL, "Russian");
	printf_s("a=%f\n", get_a(x, y, z));
	printf_s("b=%f\n", get_b(x, y, z));
}



float get_a(float x, float y, float z)
{
	float a = (2 * cos(x - M_PI / 6)) / ((1 / 2) + pow(sin(y), 2)); // Формула a
	return a;
}

float get_b(float x, float y, float z)
{
	float b = 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5)); // Формула b
	return b;
}