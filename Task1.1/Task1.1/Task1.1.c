#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
* @brief прототипы функий
* @param аргументы, получаемые в ходе уравнений
* @return получаем аргументы a и b
*/
float get_a(float x, float y, float z);
float get_b(float x, float y, float z);

/**
* @brief основная функция 
* @param аргументы, заданные условием
*/
int main()
{
    const float x = 1.426;
    const float y = -1.22;
    const float z = 3.5;

    printf("a=%f\n", get_a(x, y, z));
    printf("b=%f\n", get_b(x, y, z));

    return 0;
}

float get_a(float x, float y, float z)
{
    float a = (2 * cos(x - M_PI / 6)) / ((1 / 2.0f) + pow(sin(y), 2));
    return a;
}

float get_b(float x, float y, float z)
{
    float b = 1 + pow(z, 2) / (3 + pow(z, 2) / 5.0f);
    return b;
}