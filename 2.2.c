#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция если x < 1.2
 * @param X значение х которое вводит пользователь
 * @param A константа А
 * @return возвращает рассчитанное значение Y
 */
double First(const double X, const double A);

/**
 * @brief Функция если x >= 1.2
 * @param X значение х которое вводит пользователь
 * @param A константа А
 * @return возвращает рассчитанное значение Y
 */
double Second(const double X,const double A);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double A = 2.8;
    double Y = 0;
    printf("Enter x:\n");
    double X = getValue();
    checkValue(X);
    if (X < 1.2) {
        double Y = First(X, A);
        printf("Answer is: %lf", Y);
    }
    else if (X >= 1.2) {
        double Y = Second(X, A);
        printf("Answer is: %lf", Y);
    }
    return 0;
}

double First(const double X, const double A)
{
    return A * pow(X, 2) + 4;
}
double Second(const double X,const double A)
{
    return (A + 4 * X) * sqrt(pow(X, 2 * A));
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value < 0.0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
