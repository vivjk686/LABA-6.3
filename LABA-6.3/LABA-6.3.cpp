// LABA-6.3.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 32 (Рекурсивний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// 1. Прототипи звичайних функцій (для типу int)
// 
// Формування масиву випадковими числами (окрема функція)
void Create(int* a, const int size, const int Low, const int High, int i);

// Виведення масиву у вигляді рядка з форматним виведенням (окрема функція)
void Print(const int* a, const int size, int i);

// Обчислення / пошук найменшого елемента масиву (окрема функція)
int Min(const int* a, const int size, int i);
int Min(const int* a, const int size);
int Min(const int* a, const int size, int i, int min);

// 2. Прототипи шаблонів функцій (для довільних типів даних)

// Шаблон функції формування масиву (окрема функція)
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i);

// Шаблон функції виведення масиву (окрема функція)
template <typename T>
void Print(const T* a, const int size, int i);

// Шаблон функції обчислення / пошуку найменшого елемента (окрема функція)
template <typename T>
T Min(const T* a, const int size, int i);

template <typename T>
T Min(const T* a, const int size); 

template <typename T>
T Min(const T* a, const int size, int i, T min);

// 3. Реалізація звичайних функцій (тип int)

// Рекурсивне формування масиву випадковими цілими числами
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення елементів масиву у консоль
void Print(const int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук мінімального елемента масиву (чиста рекурсія за методичкою)
int Min(const int* a, const int size, int i)
{
    if (i >= size - 1)
        return a[size - 1];
    int min = Min(a, size, i + 1);
    return (a[i] < min) ? a[i] : min;
}

// Перевантажена функція для зручного виклику без додаткових параметрів
int Min(const int* a, const int size)
{
    if (size <= 0)
        return 0;
    return Min(a, size, 0);
}

// Рекурсивний пошук з параметром-акумулятором (для сумісності з юніт-тестами)
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

// =========================================================================
// 4. Реалізація шаблонів функцій
// =========================================================================

// Шаблон рекурсивного формування масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + static_cast<T>(rand()) * (High - Low) / static_cast<T>(RAND_MAX);
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

// Шаблон рекурсивного виведення масиву
template <typename T>
void Print(const T* a, const int size, int i)
{
    cout << setw(7) << setprecision(2) << fixed << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Шаблон рекурсивного пошуку найменшого елемента (чиста рекурсія за методичкою)
template <typename T>
T Min(const T* a, const int size, int i)
{
    if (i >= size - 1)
        return a[size - 1];
    T min = Min<T>(a, size, i + 1);
    return (a[i] < min) ? a[i] : min;
}

// Перевантажений шаблон для зручного виклику
template <typename T>
T Min(const T* a, const int size)
{
    if (size <= 0)
        return T();
    return Min<T>(a, size, 0);
}

// Шаблон рекурсивного пошуку з акумулятором
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

// =========================================================================
// 5. Головна функція програми (виключно координація викликів функцій)
// =========================================================================
#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    const int Low = -20;
    const int High = 30;

    cout << "=== Laboratorna robota 6.3 (Variant 32 - Recursion) ===" << endl;
    cout << "--- 1. Standartni funktsii (int) ---" << endl;
    
    // Формування масиву в окремій функції
    Create(a, n, Low, High, 0);
    
    // Виведення початкового масиву в окремій функції
    cout << "Masiv a:" << endl;
    Print(a, n, 0);

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
    Create<double>(b, n, dLow, dHigh, 0);
    
    // Виведення масиву дійсних чисел через шаблон в окремій функції
    cout << "Masiv b (double):" << endl;
    Print<double>(b, n, 0);

    // Обчислення мінімального елемента через шаблон в окремій функції
    double minDouble = Min<double>(b, n);
    cout << "Min<double>(b, n) = " << minDouble << endl;

    return 0;
}
#endif
