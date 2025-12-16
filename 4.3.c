#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* @brief Считывает число с проверкой ввода и проверяет на условие
* @return Число
*/
const size_t getValidForSize();

/**
* @brief Считывает число с проверкой ввода
* @return Число
*/
int getValidForDigit();

/**
* @brief Проверяет промежуток на корректность
* @param min_ - начало промежутка
* @param max_ - конец промежутка
*/
void check_min_max(const int min_, const int max_);

/**
* @brief Проверяет лежит ли число в промежутке [min;max]
* @param value - число
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void checkMinMaxForDigit(const int value, const int min, const int max);

/**
* @brief Выделяет память под массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @return Массив
*/
int** getMakeArrays(const size_t size_n, const size_t size_m);

/**
* @brief Создаёт новый массив, идентинчый элементами прообразу
* @param arr - массив прообраз
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @return Новый массив
*/
int** getCopyArray(int** arr, const size_t size_n, const size_t size_m);

/**
* @brief Проверяет, корректно ли выделилась память под массив
* @param arr - массив
* @param size_n - количество строк массива
*/
void checkArraysFromMemory(int** arr, const size_t size_n);

/**
* @brief Выводит на экран полученный массив
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void printArrays(int** arr, const size_t size_n, const size_t size_m);

/**
* @brief Заполняет массив элементами, который вводит пользователь
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void getManual(int** arr, const size_t size_n, const size_t size_m, const int min, const int max);

/**
* @brief Заполняет массив случайными элементами
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
* @param min - нижняя граница значения элемента
* @param max - верхняя граница значения элемента
*/
void getRandom(int** arr, const size_t size_n, const size_t size_m, const int min, const int max);

/**
* @brief Очищает выделенную память под массив
* @param arr - массив
* @param size_n - количество строк массива
*/
void freeArraysMemory(int** arr, const size_t size_n);

/**
* @brief Выводит новый массив согласно заданию №1
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void defTaskOne(int** arr, const size_t size_n, const size_t size_m);

/**
* @brief Выводит новый массив согласно заданию №2
* @param arr - массив
* @param size_n - количество строк массива
* @param size_m - количесвто столбцов массива
*/
void defTaskTwo(int** arr, const size_t size_n, const size_t size_m);

/**
* @param MANUAL - выбор ручного создания массива
* @param RANDOM - выбор автоматического создания массива
* @param TASK_ONE - выбор первого задания
* @param TASK_TWO - выбор второго задания
*/
enum { MANUAL = 1, RANDOM, TASK_ONE = 1, TASK_TWO };

/**
* @brief Находит количество нечётных строк (1,3,5...) для вставки первой строки
* @param size_n - количество строк массива
* @return Количество вставок
*/
const size_t findCountOddRows(const size_t size_n);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
                 system("chcp 1251");
                 system("CLS");

                 printf("Введите количество строк массива: ");
                 size_t size_n = getValidForSize();
                 printf("Введите количество столбцов массива: ");
                 size_t size_m = getValidForSize();

                 printf("\nВведите минимальное значение элемента массива: ");
                 const int min = getValidForDigit();
                 printf("Введите максимальное значение элемента массива: ");
                 const int max = getValidForDigit();
                 check_min_max(min, max);

                 printf("Элементы массива будут задаваться в промежутке [%d;%d]\n", min, max);
                 int** mainArray = getMakeArrays(size_n, size_m);
                 checkArraysFromMemory(mainArray, size_n);

                 printf("\nВыберите метод заполнение массива:\n%d - Ручное заполнение массива\n%d - Автоматическое заполнение массива\n", MANUAL, RANDOM);
                 int firstChoise = getValidForDigit();

                 switch (firstChoise)
                 {
                 case MANUAL:
                                    getManual(mainArray, size_n, size_m, min, max);
                                    break;
                 case RANDOM:
                                    getRandom(mainArray, size_n, size_m, min, max);
                                    break;
                 default:
                                    fprintf(stderr, "Error\n        Ошибка выбора");
                                    freeArraysMemory(mainArray, size_n);
                                    exit(1);
                 }

                 int** newArray = getCopyArray(mainArray, size_n, size_m);
                 checkArraysFromMemory(newArray, size_n);
                 printArrays(newArray, size_n, size_m);

                 printf("\nВыберите выполняемую операцию с массивом:\n%d - Заменить все элементы первых трех столбцов на их квадраты\n%d - Вставить после каждой нечетной строки первую строку\n", TASK_ONE, TASK_TWO);
                 int secondChoise = getValidForDigit();

                 switch (secondChoise)
                 {
                 case TASK_ONE:
                                    defTaskOne(newArray, size_n, size_m);
                                    break;
                 case TASK_TWO:
                                    defTaskTwo(newArray, size_n, size_m);
                                    break;
                 default:
                                    fprintf(stderr, "Error\n        Ошибка выбора");
                                    freeArraysMemory(newArray, size_n);
                                    freeArraysMemory(mainArray, size_n);
                                    exit(1);
                 }

                 freeArraysMemory(newArray, size_n);
                 freeArraysMemory(mainArray, size_n);
                 return 0;
}

const size_t getValidForSize()
{
                 long int value = 0;
                 if (!scanf_s("%ld", &value))
                 {
                                    fprintf(stderr, "Error\n        Ошибка ввода размерности массива");
                                    exit(1);
                 }
                 if (value < 1)
                 {
                                    fprintf(stderr, "Error\n        Ошибка ввода размерности массива");
                                    exit(1);
                 }
                 size_t output = (size_t)value;
                 return output;
}

int getValidForDigit()
{
                 int value = 0;
                 if (!scanf_s("%d", &value))
                 {
                                    fprintf(stderr, "Error\n        Ошибка ввода");
                                    exit(1);
                 }
                 return value;
}

void check_min_max(const int min_, const int max_)
{
                 if (min_ >= max_)
                 {
                                    fprintf(stderr, "Error\n        Ошибка ввода промежутка");
                                    exit(1);
                 }
}

void checkMinMaxForDigit(const int value, const int min, const int max)
{
                 if (value > max || value < min)
                 {
                                    fprintf(stderr, "Error\n        Ошибка ввода, число вне промежутка");
                                    exit(1);
                 }
}

int** getMakeArrays(const size_t size_n, const size_t size_m)
{
                 int** arr = calloc(size_n, sizeof(int*));

                 if (arr == NULL)
                 {
                                    fprintf(stderr, "Error\n        Ошибка выделения памяти под массив");
                                    exit(1);
                 }

                 for (size_t i = 0; i < size_n; i++)
                 {
                                    arr[i] = calloc(size_m, sizeof(int));
                 }
                 return arr;
}

void checkArraysFromMemory(int** arr, const size_t size_n)
{
                 if (arr == NULL)
                 {
                                    fprintf(stderr, "Error\n        Ошибка выделения памяти под массив");
                                    exit(1);
                 }
                 else
                 {
                                    for (size_t i = 0; i < size_n; i++)
                                    {
                                                 if (arr[i] == NULL)
                                                 {
                                                               fprintf(stderr, "Error\n        Ошибка выделения памяти под массив");
                                                               exit(1);
                                                 }
                                    }
                 }
}

void printArrays(int** arr, const size_t size_n, const size_t size_m)
{
                 checkArraysFromMemory(arr, size_n);
                 printf("\nПолученный массив:\n");
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < size_m; j++)
                                    {
                                                 printf("%5d", arr[i][j]);
                                    }
                                    printf("\n");
                 }
}

void getManual(int** arr, const size_t size_n, const size_t size_m, const int min, const int max)
{
                 checkArraysFromMemory(arr, size_n);
                 printf("\nВведите %zu элементов массива:\n", size_n * size_m);
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < size_m; j++)
                                    {
                                                 int num = getValidForDigit();
                                                 checkMinMaxForDigit(num, min, max);
                                                 printf("A[%zu][%zu] = %d\n", i, j, num);
                                                 arr[i][j] = num;
                                    }
                 }
}

void getRandom(int** arr, const size_t size_n, const size_t size_m, const int min, const int max)
{
                 checkArraysFromMemory(arr, size_n);
                 srand(time(NULL));
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < size_m; j++)
                                    {
                                                 arr[i][j] = rand() % (max - min + 1) + min;
                                    }
                 }
}

void freeArraysMemory(int** arr, const size_t size_n)
{
                 checkArraysFromMemory(arr, size_n);
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    free(arr[i]);
                 }
                 free(arr);
}

int** getCopyArray(int** arr, const size_t size_n, const size_t size_m)
{
                 checkArraysFromMemory(arr, size_n);
                 int** array = getMakeArrays(size_n, size_m);
                 checkArraysFromMemory(array, size_n);
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < size_m; j++)
                                    {
                                                 array[i][j] = arr[i][j];
                                    }
                 }
                 return array;
}

void defTaskOne(int** arr, const size_t size_n, const size_t size_m)
{
                 checkArraysFromMemory(arr, size_n);
                 size_t limit = 3;
                 if (size_m < 3)
                 {
                                    limit = size_m;
                 }
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < limit; j++)
                                    {
                                                 arr[i][j] = arr[i][j] * arr[i][j];
                                    }
                 }
                 printArrays(arr, size_n, size_m);
}

void defTaskTwo(int** arr, const size_t size_n, const size_t size_m)
{
                 checkArraysFromMemory(arr, size_n);
                 const size_t count = findCountOddRows(size_n);
                 const size_t new_n = size_n + count;

                 int** newarr = getMakeArrays(new_n, size_m);
                 checkArraysFromMemory(newarr, new_n);

                 size_t next_idx = 0;
                 for (size_t i = 0; i < size_n; i++)
                 {
                                    for (size_t j = 0; j < size_m; j++)
                                    {
                                                 newarr[next_idx][j] = arr[i][j];
                                    }
                                    next_idx++;

                                    if (i % 2 == 0)
                                    {
                                                 for (size_t j = 0; j < size_m; j++)
                                                 {
                                                               newarr[next_idx][j] = arr[0][j];
                                                 }
                                                 next_idx++;
                                    }
                 }

                 if (next_idx != new_n)
                 {
                                    fprintf(stderr, "Error");
                                    freeArraysMemory(newarr, new_n);
                                    exit(1);
                 }

                 printArrays(newarr, new_n, size_m);
                 printf("\nДобавлено %zu строк\n", count);
                 freeArraysMemory(newarr, new_n);
}

const size_t findCountOddRows(const size_t size_n)
{
                 return (size_n + 1) / 2;
}
