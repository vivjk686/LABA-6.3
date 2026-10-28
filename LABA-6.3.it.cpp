// LABA-6.3.it.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 32 (Ітераційний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// =========================================================================
// 1. Прототипи звичайних функцій (для типу int)
// =========================================================================

// Формування масиву випадковими числами (окрема функція)
void Create(int* a, const int size, const int Low, const int High);

// Виведення масиву у вигляді рядка з форматним виведенням (окрема функція)
void Print(const int* a, const int size);

// Обчислення / пошук найменшого елемента масиву (окрема функція)
int Min(const int* a, const int size);

// =========================================================================
// 2. Прототипи шаблонів функцій (для довільних типів даних)
// =========================================================================

// Шаблон функції формування масиву (окрема функція)
template <typename T>
void Create(T* a, const int size, const T Low, const T High);

// Шаблон функції виведення масиву (окрема функція)
template <typename T>
void Print(const T* a, const int size);

// Шаблон функції обчислення / пошуку найменшого елемента (окрема функція)
template <typename T>
T Min(const T* a, const int size);

// =========================================================================
// 3. Реалізація звичайних функцій (тип int)
// =========================================================================

// Ітераційне формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Ітераційне виведення елементів масиву
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// Ітераційний пошук найменшого елемента (Варіант 32)
int Min(const int* a, const int size)
{
    int min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// =========================================================================
// 4. Реалізація шаблонів функцій
// =========================================================================

// Шаблон ітераційного формування масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + static_cast<T>(rand()) * (High - Low) / static_cast<T>(RAND_MAX);
}

// Шаблон ітераційного виведення масиву
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(7) << setprecision(2) << fixed << a[i];
    cout << endl;
}

// Шаблон ітераційного пошуку найменшого елемента (Варіант 32)
template <typename T>
T Min(const T* a, const int size)
{
    T min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// =========================================================================
// 5. Головна функція програми (виключно координація викликів функцій)
// =========================================================================
#ifndef UNIT_TESTING_IT
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    const int Low = -20;
    const int High = 30;

    cout << "=== Laboratorna robota 6.3 (Variant 32 - Iteration) ===" << endl;
    cout << "--- 1. Standartni funktsii (int) ---" << endl;
    
    // Формування масиву в окремій функції
    Create(a, n, Low, High);
    
    // Виведення початкового масиву в окремій функції
    cout << "Masiv a:" << endl;
    Print(a, n);

    // Обчислення мінімального елемента в окремій функції
    int minInt = Min(a, n);
    cout << "Min(a, n) = " << minInt << endl << endl;

    cout << "--- 2. Shabloni funktsiy ---" << endl;
    // Обчислення за допомогою шаблону
    cout << "Min<int>(a, n) = " << Min<int>(a, n) << endl;

    double b[n];
    const double dLow = -15.5;
    const double dHigh = 25.5;
    
    // Формування масиву дійсних чисел через шаблон в окремій функції
    Create<double>(b, n, dLow, dHigh);
    
    // Виведення масиву дійсних чисел через шаблон в окремій функції
    cout << "Masiv b (double):" << endl;
    Print<double>(b, n);

    // Обчислення мінімального елемента через шаблон в окремій функції
    double minDouble = Min<double>(b, n);
    cout << "Min<double>(b, n) = " << minDouble << endl;

    return 0;
}
#endif
