// Lab_7_2.rec.cpp
// Давиденко Михайло
// Лабораторна робота № 7.2)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int i, const int j, const int k, const int n, const int Low, const int High) {
    if (i < k) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            Create(a, i, j + 1, k, n, Low, High);
        }
        else {
            Create(a, i + 1, 0, k, n, Low, High);
        }
    }
}

void Print(int** a, const int i, const int j, const int k, const int n) {
    if (i < k) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            Print(a, i, j + 1, k, n);
        }
        else {
            cout << endl;
            Print(a, i + 1, 0, k, n);
        }
    }
}

int FindMinInRow(int* row, const int j, const int n, int min) {
    if (j < n) {
        if (row[j] < min) {
            min = row[j];
        }
        return FindMinInRow(row, j + 1, n, min);
    }
    return min;
}

int FindMaxFromMins(int** a, const int i, const int k, const int n, int max) {
    if (i < k) {
        int minInRow = FindMinInRow(a[i], 0, n, a[i][0]);
        if (minInRow > max) {
            max = minInRow;
        }
        return FindMaxFromMins(a, i + 1, k, n, max);
    }
    return max;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 99;
    int k;
    int n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    int** a = new int* [k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }
    Create(a, 0, 0, k, n, Low, High);
    Print(a, 0, 0, k, n);

    int max = FindMinInRow(a[0], 0, n, a[0][0]);
    int maxValueFromMinElement = FindMaxFromMins(a, 0, k, n,max);
    cout << "The largest of the minimum elements across all rows of the matrix(rec): " << maxValueFromMinElement << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
