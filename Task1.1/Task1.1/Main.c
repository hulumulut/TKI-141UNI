#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <locale.h>
// ������� ��� ������ ��������� a
void get_a(float x, float y, float z)
{
	float a = (2 * cos(x - M_PI / 6)) / ((1 / 2) + pow(sin(y), 2)); // ������� a
	printf_s("a=%f", a);
}
// ������� ��� ������ ��������� b
void get_b(float x, float y, float z)
{
	float b = 1 + (pow(z, 2)) / (3 + (pow(z, 2) / 5)); // ������� b
	printf_s("b=%f", b);
}
// �������� x,y,z
int main()
{
	get_a(1.426, -1.22, 3.5);
	get_b(1.426, -1.22, 3.5);
}