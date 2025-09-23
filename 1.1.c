#include <locale.h>// для конкретного отображения русского языка
#include <stdio.h>
#include <math.h>

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @return возвращает рассчитанное значение
 */
double compute_a(const double x);

// Функция для вычисления b
/**
 * @brief Рассчитывает функцию B по заданной формуле
 * @param y - значение параметра y
 * @param x - значение параметра x
 * @return возвращает рассчитанное значение
 */
double compute_b(const double x, const double y);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main() {
   
    setlocale(LC_ALL, "Rus");
    // Заданные константы
    const double x = 0.335;
    const double y = 0.025;

    // Вычисление через функции
    const double a = compute_a(x);
    const double b = compute_b(x, y);

    // Вывод исходных данных
    printf("Исходные данные:\n");
    printf("x = %.6f\n", x);
    printf("y = %.6f\n\n", y);

    // Вывод результатов вычислений
    printf("Результаты вычислений:\n");
    printf("a = %.6f\n", a);
    printf("b = %.6f\n", b);

    return 0;
}
double compute_a(const double x) {
    return 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);
}
double compute_b(const double x,const double y) {
    return x * (sin(pow(x, 3)) + pow(cos(y), 2));
}
