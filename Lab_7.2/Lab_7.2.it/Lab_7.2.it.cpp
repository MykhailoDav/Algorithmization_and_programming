// Lab_7_2.it.cpp
// Давиденко Михайло
// Лабораторна робота № 7.2)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k,const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void FindMaxFromMins(int** a, const int k, const int n, int& maxValueFromMinElement)
{
	int minFromRow;
	for (int i = 0; i < k; i++)
	{
		int minFromRow = a[i][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < minFromRow)
				minFromRow = a[i][j];
		}
		if (i == 0)
			maxValueFromMinElement = minFromRow;
		if (minFromRow > maxValueFromMinElement)
			maxValueFromMinElement = minFromRow;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 1;
	int High = 99;
	int k ;
	int n ;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	Print(a, k, n);

	int maxValueFromMinElement;
	FindMaxFromMins(a, k, n, maxValueFromMinElement);
	cout<<"The largest of the minimum elements across all rows of the matrix: " << maxValueFromMinElement << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
