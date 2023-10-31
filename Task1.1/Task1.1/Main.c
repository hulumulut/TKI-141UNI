#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <locale.h>
// Функция для поиска аргумента a
void get_a(float x, float y, float z)
{
	float a = (2 * cos(x - M_PI / 6)) / ((1 / 2) + pow(sin(y), 2)); // Формула a
	printf_s("a=%f", a);
}
// Функция для поиска аргумента b
void get_b(float x, float y, float z)
{
	float b = 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5)); // Формула b
	printf_s("b=%f", b);
}
// Значения x,y,z
int main()
{
	get_a(1.426, -1.22, 3.5);
	get_b(1.426, -1.22, 3.5);
}