#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает площадь трапеции
 * @param H Высота трапеции
 * @param MidLine средняя линия трапеции
 * @return возвращает рассчитанную площадь
 */
double getArea1(const double H, const double MidLine);

/**
 * @brief площадь круга
 * @param R радиус круга
 * @return возвращает рассчитанную площадь
 */
double getArea2(const double R);

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
    printf("Введите среднюю линию и высоту трапеции:\n");
    double H = getValue();
    checkValue(H);
    double MidLine = getValue();
    checkValue(MidLine);
    printf("Площадь трапеции равна %.2lf\n", getArea1(H, MidLine));
    printf("Введите радиус круга:\n");
    double R = getValue();
    checkValue(R);
    printf("Площадь Круга равна %.2lf\n", getArea2(R));
    return 0;
}

double getArea1(const double H, const double MidLine)
{
    return MidLine * H;
}
double getArea2(const double R)
{
    return M_PI * pow(R, 2);
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
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
