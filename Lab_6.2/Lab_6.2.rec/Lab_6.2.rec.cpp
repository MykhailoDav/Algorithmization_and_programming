#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
	b[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(b, size, Low, High, i + 1);
}
	void Print(int* b, const int size, int i)
	{
		cout << setw(4) << b[i];
		if (i < size - 1)
			Print(b, size, i + 1);
		else
			cout << endl;
	}
	int Max(int* a, const int size, int i, int max)
	{
		if (a[i] > max)
			max = a[i];
		if (i < size - 1)
			return Max(a, size, i + 1, max);
		else
			return max;
	}
	int Min(int* a, const int size, int i, int min)
	{
		if (a[i] < min)
			min = a[i];
		if (i < size - 1)
			return Max(a, size, i + 1, min);
		else
			return min;
	}
	int main()
	{
		srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
		const int n = 7;
		int a[n];
		int Low = -100;
		int High = 100;
		Create(a, n, Low, High, 0);
		Print(a, n, 0);
		cout << "max = " << Max(a, n, 1, a[0]) << endl;
		cout << "min = " << Min(a, n, 1, a[0]) << endl;
		return 0;
	}