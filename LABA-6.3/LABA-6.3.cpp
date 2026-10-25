#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи звичайних функцій
void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
int Min(int* a, const int size, int i, int min);
int Min(int* a, const int size);

// Прототипи шаблонних функцій
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i);

template <typename T>
void Print(T* a, const int size, int i);

template <typename T>
T Min(T* a, const int size, int i, T min);

template <typename T>
T Min(T* a, const int size);

// --- Реалізація звичайних функцій (для int) ---

// Рекурсивне формування масиву
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук найменшого елемента (Варіант 32)
int Min(int* a, const int size, int i, int min)
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

// Допоміжна перевантажена функція для зручного виклику
int Min(int* a, const int size)
{
    return Min(a, size, 1, a[0]);
}

// --- Реалізація шаблонних функцій ---

// Рекурсивне формування масиву через шаблон
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (High - Low)));
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву через шаблон
template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(7) << setprecision(2) << fixed << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук найменшого елемента через шаблон (Варіант 32)
template <typename T>
T Min(T* a, const int size, int i, T min)
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

// Допоміжна перевантажена шаблонна функція
template <typename T>
T Min(T* a, const int size)
{
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

    int minInt = Min(a, n, 1, a[0]);
    cout << "Min(a, n) = " << minInt << endl << endl;

    cout << "--- 2. Shabloni funktsiy ---" << endl;
    cout << "Min<int>(a, n) = " << Min<int>(a, n, 1, a[0]) << endl;

    double b[n];
    double dLow = -15.5, dHigh = 25.5;
    Create<double>(b, n, dLow, dHigh, 0);
    cout << "Masiv b (double):" << endl;
    Print<double>(b, n, 0);

    double minDouble = Min<double>(b, n, 1, b[0]);
    cout << "Min<double>(b, n) = " << minDouble << endl;

    return 0;
}
#endif
