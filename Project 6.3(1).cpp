#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи звичайних рекурсивних функцій (non-template / regular functions)
void CreateRecursive(int* a, const int size, const int Low, const int High, int i = 0);
void PrintRecursive(const int* a, const int size, int i = 0);
int MinRecursive(const int* a, const int size, int i = 0);

// Прототипи шаблонів рекурсивних функцій (template functions)
template <typename T>
void CreateTemplateRecursive(T* a, const int size, const T Low, const T High, int i = 0);

template <typename T>
void PrintTemplateRecursive(const T* a, const int size, int i = 0);

template <typename T>
T MinTemplateRecursive(const T* a, const int size, int i = 0);

int main()
{
    // Виправлено time(nullptr)
    srand((unsigned)time(nullptr));
    const int n = 10;

    // -------------------------------------------------------------
    // 1. Обробка за допомогою звичайних рекурсивних функцій (int)
    // -------------------------------------------------------------
    cout << "Ordinary functions" << endl;
    int* a = new int[n];

    CreateRecursive(a, n, -10, 10);
    cout << "a = ";
    PrintRecursive(a, n);

    // Просто викликаємо MinRecursive(a, n)
    int min_val = MinRecursive(a, n);
    cout << "MinRecursive(a, n) = " << min_val << endl << endl;

    // -------------------------------------------------------------
    // 2. Обробка за допомогою шаблонів рекурсивних функцій (double)
    // -------------------------------------------------------------
    cout << "Function templates " << endl;
    double* b = new double[n];

    CreateTemplateRecursive(b, n, -10.0, 10.0);
    cout << "b = ";
    PrintTemplateRecursive(b, n);

    // Просто викликаємо MinTemplateRecursive(b, n)
    double min_val_b = MinTemplateRecursive(b, n);
    cout << "MinTemplateRecursive(b, n) = " << min_val_b << endl;

    // Звільнення пам'яті
    delete[] a;
    delete[] b;

    return 0;
}

// Рекурсивне формування масиву
void CreateRecursive(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        CreateRecursive(a, size, Low, High, i + 1);
}

// Рекурсивне виведення масиву
void PrintRecursive(const int* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        PrintRecursive(a, size, i + 1);
    else
        cout << endl;
}

// Елегантне рекурсивне знаходження мінімуму
int MinRecursive(const int* a, const int size, int i)
{
    if (i == size - 1)
        return a[i];

    int min = MinRecursive(a, size, i + 1);
    return (a[i] < min) ? a[i] : min;
}

// --- ШАБЛОНИ РЕКУРСИВНИХ ФУНКЦІЙ ---

template <typename T>
void CreateTemplateRecursive(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
    if (i < size - 1)
        CreateTemplateRecursive(a, size, Low, High, i + 1);
}

template <typename T>
void PrintTemplateRecursive(const T* a, const int size, int i)
{
    cout << setw(8) << setprecision(2) << fixed << a[i];
    if (i < size - 1)
        PrintTemplateRecursive(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
T MinTemplateRecursive(const T* a, const int size, int i)
{
    if (i == size - 1)
        return a[i];

    T min = MinTemplateRecursive(a, size, i + 1);
    return (a[i] < min) ? a[i] : min;
}