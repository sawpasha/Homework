#include <stdio.h>

/**
 * @brief Вычисляет общее сопротивдение
 * @param R1 сопротивление резистора 1
 * @param R2 сопротивление резистора 2
 * @param R2 сопротивления резистора 3
 * @return возвращает рассчитанное сопротивление
 */
double res(const double R1,const double R2,const double R3);
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main() {
	double R1 = 0;
    double R2 = 0;
    double R3 = 0;
	printf("enter resistence R1,R2,R3 -->\n");
	scanf_s("%lf %lf %lf", &R1, &R2, &R3);
	printf("Resistense is: %.2lf", res(R1, R2, R3));
}
double res(const double R1,const double R2,const double R3)
{
	return 1.0 / (1.0 / R1 + 1.0 / R2 + 1.0 / R3);
}
