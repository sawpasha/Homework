#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция если x < 0
 * @param X значение х которое вводит пользователь
 * @return возвращает рассчитанное значение для отрицательного числа
 */
double First(const double X);

/**
 * @brief Функция если x >= 0
 * @param X значение х которое вводит пользователь
 * @return возвращает рассчитанное значение для положительного числа
 */
double Second(const double X);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double A1 = getValue();
    double A2 = getValue();
    double A3 = getValue();
    if (A1 < 0) {
        printf("в четвертой степени:%lf\n", First(A1));
    }
    else {
        printf("в квадрате:%lf\n", Second(A1));
    }
    if (A2 < 0) {
        printf("в четвертой степени:%lf\n", First(A2));
    }
    else {
        printf("в квадрате:%lf\n", Second(A2));
    }
    if (A3 < 0) {
        printf("в четвертой степени:%lf\n", First(A3));
    }
    else {
        printf("в квадрате:%lf\n", Second(A3));
    }
    return 0;
}

double First(const double X)
{
    return pow(X,4);
}
double Second(const double X)
{
    return pow(X,2);
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
