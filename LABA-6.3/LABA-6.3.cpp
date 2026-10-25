// LABA-6.3.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 32 (Рекурсивний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи функцій (звичайні функції для типу int)
void Create(int* a, const int size, const int Low, const int High, int i);
void Print(const int* a, const int size, int i);
int Min(const int* a, const int size, int i, int min);
int Min(const int* a, const int size);

// Прототипи шаблонів функцій
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i);

template <typename T>
void Print(const T* a, const int size, int i);

template <typename T>
T Min(const T* a, const int size, int i, T min);

template <typename T>
T Min(const T* a, const int size);

// --- 1. Реалізація звичайних функцій (тип int) ---

// Рекурсивне формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення елементів масиву
void Print(const int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук мінімального елемента масиву (Варіант 32)
int Min(const int* a, const int size, int i, int min)
{
    if (i >= size)
        return min;
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}

// Допоміжна функція пошуку мінімального елемента
int Min(const int* a, const int size)
{
    if (size <= 0)
        return 0;
    return Min(a, size, 1, a[0]);
}

// --- 2. Реалізація шаблонів функцій ---

// Рекурсивне формування масиву для шаблону
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (High - Low)));
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву для шаблону
template <typename T>
void Print(const T* a, const int size, int i)
{
    cout << setw(7) << setprecision(2) << fixed << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук найменшого елемента для шаблону (Варіант 32)
template <typename T>
T Min(const T* a, const int size, int i, T min)
{
    if (i >= size)
        return min;
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min<T>(a, size, i + 1, min);
    else
        return min;
}

// Допоміжна функція пошуку найменшого елемента для шаблону
template <typename T>
T Min(const T* a, const int size)
{
    if (size <= 0)
        return T();
    return Min<T>(a, size, 1, a[0]);
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20, High = 30;

    cout << "=== Laboratorna robota 6.3 (Variant 32 - Recursion) ===" << endl;
    cout << "--- 1. Standartni funktsii (int) ---" << endl;
    Create(a, n, Low, High, 0);
    cout << "Masiv a:" << endl;
    Print(a, n, 0);

    int minInt = Min(a, n);
    cout << "Min(a, n) = " << minInt << endl << endl;

    cout << "--- 2. Shabloni funktsiy ---" << endl;
    cout << "Min<int>(a, n) = " << Min<int>(a, n) << endl;

    double b[n];
    double dLow = -15.5, dHigh = 25.5;
    Create<double>(b, n, dLow, dHigh, 0);
    cout << "Masiv b (double):" << endl;
    Print<double>(b, n, 0);

    double minDouble = Min<double>(b, n);
    cout << "Min<double>(b, n) = " << minDouble << endl;

    return 0;
}
#endif
