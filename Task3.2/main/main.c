#include <stdio.h> 
#include <math.h>
#include <errno.h>
#include <stdlib.h>	
#include <float.h>
#include <locale.h>
/*
* @brief вычисляет текущий член последовательности
* @param k - порядковый номер
* @return значение члена последовательности
*/
double get_recurrent(double k);

/*
* @brief вычисляет сумму всех членов последовательности, не меньших заданного числа e
* @param n - максимальное количество членов последовательности для вычисления
* @param e - точность вычисления ряда последовательности
* @return сумма всех членов последовательности, не меньших заданного числа e
*/
double get_sumwithE(double n, double e);

/*
* @brief вычисляет сумму ряда до указанного номера
* @param n - номер члена ряда, до которого нужно вычислить сумму
* @return щначение суммы ряда
*/
double get_sum(double n);

/*
* @brief проверка ввод пользователя
* @return значение
*/
double get_value();

/*
* @brief точка входа в программу
* @return возвращает 0 в случае успешного выполнения программы
*/
int main()
{
	setlocale(LC_ALL, "ru");

	printf_s("Введите количество членов ряда\n");
	double n = get_value();
	printf_s("Задайте число e\n");
	double e = get_value();
	double summ = get_sum(n);
	double sumwithE = get_sumwithE(n, e);
	printf_s("Сумма первых членов последовательности = %.15lf\n", summ);
	printf_s("Сумма всех членов последовательности, не меньших заданного числа e = %.15lf\n", sumwithE);
	return 0;
}

double get_recurrent(double k)
{
	return (1.0 / ((k + 2) * (k + 3)));
}

double get_sumwithE(double n, double e)
{
	double current = 1.0;
	double sum = current;
	int k = 1;
	if (fabs(current) - e >= DBL_EPSILON)
	{
		for (k; k <= n; k++)
		{
			current *= get_recurrent(k);
			sum += current;
		}
	}
	return sum;
}

double get_sum(double n)
{
	double current = 1.0;
	double sum = current;
	for (int k = 1; k < n; k++)
	{
		current *= get_recurrent(k);
		sum += current;
	}
	return sum;
}

double get_value()
{
	double value;
	int res = scanf_s("%lf", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("Ошибка");
		abort();
	}
	return value;
}