#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает сумму n членов последовательности
* @param n - число членов последовательности
* @return Рассчитанное значение
*/
double defSumm(const int n);

/**
* @brief Рассчитывает сумму по рекуррентной формуле с заданной точностью e
* @param e - точность рассчёта
* @return Рассчитанное значение
*/
double defSummE(const double e);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double getValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void checkValueForN(const double input);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите целое число n: ");
	int n = (int) getValid();
	checkValueForN(n);

	printf("Сумма первых %d членов последовательности = %.10lf\n\n", n, defSumm(n));

	printf("Введите число e: ");
	double e = getValid();
	checkValueForN(e);

	printf("Сумма членов последовательности с точностью %.4lf = %.10lf\n", e, defSummE(e));

	return 0;
}

double getValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error\n");
		exit(1);
	}

	return valid;
}

void checkValueForN(const double input)
{
	if (!(input > DBL_EPSILON))
	{
		printf("Error\n");
		exit(1);
	}
}

double defSumm(const int n)
{
	double current = 1.0;
	double result = current;
	for (int i = 0; i < n - 1; i++)
	{
		current *= getRecurent(i);
		result += current;
	}
	return result;
}

double defSummE(const double e)
{
	double current = 1.0;
	double result = current; // Исправлено: сумма начинается с первого элемента
	for (int i = 0; fabs(current) >= e; i++)
	{
		current *= getRecurent(i);
		result += current;
	}
	return result;
}

double getRecurent(const int i)
{
	return -1.0 / ((i + 1) * (i + 2));
}
