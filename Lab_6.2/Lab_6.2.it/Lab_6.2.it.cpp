#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* b, const int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << setw(4) << b[i];
	cout << "]" << endl;
}

int Max(int* a, const int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
int Min(int* a, const int size)
{
	int min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 7;
	int a[n];
	int Low = -100;
	int High = 100;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "max = " << Max(a, n) << endl;
	cout << "min = " << Min(a, n) << endl;
	return 0;
}