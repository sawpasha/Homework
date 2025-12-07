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
 * @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
 * @return Считанное значение
 */
int getValid(void);

/**
 * @brief Проверяет что переменная не меньше единицы
 * @param input - значение проверяемой переменной
 */
void checkValueForN(const int input);

/**
 * @brief Заполняет массив случайными числами
 * @param arr указатель на массив
 * @param n размер массива
 * @param min минимальное значение случайного числа
 * @param max максимальное значение случайного числа
 */
void fillRandom(int* arr, size_t n, const int min, const int max);

/**
 * @brief Заполняет массив числами с клавиатуры
 * @param arr указатель на массив
 * @param n размер массива
 */
void fillKeyboard(int* arr, const size_t n);

/**
 * @brief Выводит массив на экран
 * @param arr указатель на массив
 * @param n размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Находит сумму элементов с нечетными индексами
 * @param arr указатель на массив
 * @param n размер массива
 * @return сумма элементов с нечетными индексами
 */
int sumOddIndex(const int* arr, const size_t n);

/**
 * @brief Подсчитывает элементы больше A и кратные 5
 * @param arr указатель на массив
 * @param n размер массива
 * @param A заданное число для сравнения
 * @return количество элементов, удовлетворяющих условию
 */
int countGreaterAndMultiple(const int* arr, const size_t n, const int A);

/**
 * @brief Делит элементы с четными индексами на первый элемент
 * @param src указатель на исходный массив
 * @param dest указатель на массив для результатов
 * @param n размер массива
 */
void divideEvenByFirst(const int* src, int* dest, const size_t n);

/**
 * @brief Создает копию массива
 * @param src исходный массив
 * @param n размер массива
 * @return указатель на копию массива
 */
int* copyArray(const int* src, const size_t n);

int main(void)
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    // Ввод размера массива с проверкой по аналогии с примером
    printf("Введите размер массива: ");
    size_t n = (size_t)getValid();
    checkValueForN((int)n);

    // Выделение памяти
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    // Выбор способа заполнения
    printf("\nВыберите способ заполнения массива:\n");
    printf("%d - Случайные числа\n", MENU_RANDOM);
    printf("%d - Ввод с клавиатуры\n", MENU_KEYBOARD);
    printf("Ваш выбор: ");
    int choice = getValid();

    switch (choice) {
    case MENU_RANDOM:
        fillRandom(arr, n, MIN_VALUE, MAX_VALUE);
        break;
    case MENU_KEYBOARD:
        fillKeyboard(arr, n);
        break;
    default:
        fprintf(stderr, "Error: неверный выбор\n");
        free(arr);
        exit(1);
    }

    // Вывод исходного массива
    printf("\nИсходный массив:\n");
    printArray(arr, n);

    // Задание 1
    printf("\n1. Сумма элементов с нечетными индексами: %d\n",
        sumOddIndex(arr, n));

    // Задание 2 - ввод A с проверкой по аналогии (через getValid)
    printf("\nВведите число A для сравнения: ");
    int A = getValid();
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
            fprintf(stderr, "Ошибка выделения памяти для копии массива\n");
        }
    }
    else {
printf("Ошибка: первый элемент равен 0, деление невозможно\n");
    }

    free(arr);
    return 0;
}

int getValid(void)
{
    int valid = 0;
#ifdef _MSC_VER
    if (!scanf_s("%d", &valid)) {
#else
    if (!scanf("%d", &valid)) {
#endif
        fprintf(stderr, "Error: некорректный ввод\n");
        exit(1);
    }
    return valid;
    }

void checkValueForN(const int input)
{
    if (input < 1) {
        fprintf(stderr, "Error\nЧисло должно быть не меньше 1\n");
        exit(1);
    }
}

void fillRandom(int* arr, size_t n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void fillKeyboard(int* arr, const size_t n)
{
    printf("Введите %zu элементов массива:\n", n);
    for (size_t i = 0; i < n; i++) {
        printf("arr[%zu] = ", i);
        arr[i] = getValid();
    }
}

void printArray(const int* arr, const size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumOddIndex(const int* arr, const size_t n)
{
    int sum = 0;
    for (size_t i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int countGreaterAndMultiple(const int* arr, const size_t n, const int A)
{
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

void divideEvenByFirst(const int* src, int* dest, const size_t n)
{
    const int first = src[0];
    for (size_t i = 0; i < n; i++) {
        if (i % 2 == 0) {
            dest[i] = src[i] / first;
        }
        else {
            dest[i] = src[i]; // Нечетные индексы остаются без изменений
        }
    }
}

int* copyArray(const int* src, const size_t n)
{
    int* dest = (int*)malloc(n * sizeof(int));
    if (dest != NULL) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    }
    return dest;
}
