#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Константы для меню выбора
enum {
    MENU_RANDOM = 1,
    MENU_KEYBOARD = 2
};

// Диапазон случайных чисел
enum {
    MIN_VALUE = 1,
    MAX_VALUE = 100
};

/**
 * @brief Заполняет массив случайными числами
 * @param arr указатель на массив
 * @param n размер массива
 * @param min минимальное значение случайного числа
 * @param max максимальное значение случайного числа
 */
void fillRandom(int* arr, size_t n, int min, int max);

/**
 * @brief Заполняет массив числами с клавиатуры
 * @param arr указатель на массив
 * @param n размер массива
 */
void fillKeyboard(int* arr, size_t n);

/**
 * @brief Выводит массив на экран
 * @param arr указатель на массив
 * @param n размер массива
 */
void printArray(const int* arr, size_t n);

/**
 * @brief Находит сумму элементов с нечетными индексами
 * @param arr указатель на массив
 * @param n размер массива
 * @return сумма элементов с нечетными индексами
 */
int sumOddIndex(const int* arr, size_t n);

/**
 * @brief Подсчитывает элементы больше A и кратные 5
 * @param arr указатель на массив
 * @param n размер массива
 * @param A заданное число для сравнения
 * @return количество элементов, удовлетворяющих условию
 */
int countGreaterAndMultiple(const int* arr, size_t n, int A);

/**
 * @brief Делит элементы с четными индексами на первый элемент
 * @param src указатель на исходный массив
 * @param dest указатель на массив для результатов
 * @param n размер массива
 */
void divideEvenByFirst(const int* src, int* dest, size_t n);

/**
 * @brief Создает копию массива
 * @param src исходный массив
 * @param n размер массива
 * @return указатель на копию массива
 */
int* copyArray(const int* src, size_t n);

int main(void)
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    // Ввод размера массива
    size_t n = 0;
    printf("Введите размер массива: ");
    scanf("%zu", &n);

    if (n == 0) {
        printf("Ошибка: размер массива должен быть положительным\n");
        return 1;
    }

    // Выделение памяти
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    // Выбор способа заполнения
    int choice = 0;
    printf("\nВыберите способ заполнения массива:\n");
    printf("%d - Случайные числа\n", MENU_RANDOM);
    printf("%d - Ввод с клавиатуры\n", MENU_KEYBOARD);
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
    case MENU_RANDOM:
        fillRandom(arr, n, MIN_VALUE, MAX_VALUE);
        break;
    case MENU_KEYBOARD:
        fillKeyboard(arr, n);
        break;
    default:
        printf("Неверный выбор. Используются случайные числа.\n");
        fillRandom(arr, n, MIN_VALUE, MAX_VALUE);
    }

    // Вывод исходного массива
    printf("\nИсходный массив:\n");
    printArray(arr, n);

    // Задание 1
    printf("\n1. Сумма элементов с нечетными индексами: %d\n", 
           sumOddIndex(arr, n));

    // Задание 2
    int A = 0;
    printf("\nВведите число A для сравнения: ");
    scanf("%d", &A);
    printf("2. Количество элементов > %d и кратных 5: %d\n", A, 
           countGreaterAndMultiple(arr, n, A));

    // Задание 3
    printf("\n3. Деление элементов с четными индексами на первый элемент:\n");
    if (arr[0] != 0) {
        // Создаем копию массива для преобразований
        int* tempArr = copyArray(arr, n);
        if (tempArr != NULL) {
            divideEvenByFirst(arr, tempArr, n);
            printf("Массив после преобразования:\n");
            printArray(tempArr, n);
            free(tempArr);
        }
        else {
            printf("Ошибка выделения памяти для копии массива\n");
        }
    }
    else {
        printf("Ошибка: первый элемент равен 0, деление невозможно\n");
    }

    free(arr);
    return 0;
}

void fillRandom(int* arr, size_t n, int min, int max)
{
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void fillKeyboard(int* arr, size_t n)
{
    printf("Введите %zu элементов массива:\n", n);
    for (size_t i = 0; i < n; i++) {
        printf("arr[%zu] = ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(const int* arr, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumOddIndex(const int* arr, size_t n)
{
    int sum = 0;
    for (size_t i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int countGreaterAndMultiple(const int* arr, size_t n, int A)
{
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

void divideEvenByFirst(const int* src, int* dest, size_t n)
{
    int first = src[0];
    for (size_t i = 0; i < n; i++) {
        if (i % 2 == 0) {
            dest[i] = src[i] / first;
        }
        else {
            dest[i] = src[i]; // Нечетные индексы остаются без изменений
        }
    }
}

int* copyArray(const int* src, size_t n)
{
    int* dest = (int*)malloc(n * sizeof(int));
    if (dest != NULL) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    }
    return dest;
}
