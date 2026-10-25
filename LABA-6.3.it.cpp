#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи звичайних функцій
void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int Min(int* a, const int size);

// Прототипи шаблонних функцій
template <typename T>
void Create(T* a, const int size, const T Low, const T High);

template <typename T>
void Print(T* a, const int size);

template <typename T>
T Min(T* a, const int size);

// --- Реалізація звичайних функцій (для int) ---

// Ітераційне формування масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Ітераційне виведення масиву
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// Ітераційний пошук найменшого елемента (Варіант 32)
int Min(int* a, const int size)
{
    int min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// --- Реалізація шаблонних функцій ---

// Ітераційне формування масиву через шаблон
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (High - Low)));
}

// Ітераційне виведення масиву через шаблон
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(7) << setprecision(2) << fixed << a[i];
    cout << endl;
}

// Ітераційний пошук найменшого елемента через шаблон (Варіант 32)
template <typename T>
T Min(T* a, const int size)
{
    T min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

#ifndef UNIT_TESTING_IT
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20, High = 30;

    cout << "=== Laboratorna robota 6.3 (Variant 32 - Iteration) ===" << endl;
    cout << "--- 1. Standartni funktsii (int) ---" << endl;
    Create(a, n, Low, High);
    cout << "Masiv a:" << endl;
    Print(a, n);

    int minInt = Min(a, n);
    cout << "Min(a, n) = " << minInt << endl << endl;

    cout << "--- 2. Shabloni funktsiy ---" << endl;
    cout << "Min<int>(a, n) = " << Min<int>(a, n) << endl;

    double b[n];
    double dLow = -15.5, dHigh = 25.5;
    Create<double>(b, n, dLow, dHigh);
    cout << "Masiv b (double):" << endl;
    Print<double>(b, n);

    double minDouble = Min<double>(b, n);
    cout << "Min<double>(b, n) = " << minDouble << endl;

    return 0;
}
#endif
