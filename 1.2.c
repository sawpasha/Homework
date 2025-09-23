#include <stdio.h>
#include <math.h>
/**
 * @brief Рассчитывает обьем по заданной формуле
 * @param R - Радиус окружности
 * @return возвращает рассчитанное значение
 */
double Volume(const double R);

/**
 * @brief Рассчитывает площадь по заданной формуле
 * @param R - Радиус окружности
 * @return возвращает рассчитанное значение
 */
double Surface(const double R);
/**
 * @brief основное тело программы
 * @return возвращает 0 когда программа проработала успешно
 */
int main() 
{
    double R = 0;
    printf("Введите радиус шара: ");
    scanf("%lf", &R);
    printf("Объем шара: %.3f\n", Volume(R));
    printf("Площадь поверхности шара: %.3f\n", Surface(R));
    return 0;
}
double Volume(const double R) 
{
    return (4.0 / 3.0) * M_PI * pow(R, 3);
}
double Surface(const double R) 
{
    return 4.0 * M_PI * pow(R, 2);
}
