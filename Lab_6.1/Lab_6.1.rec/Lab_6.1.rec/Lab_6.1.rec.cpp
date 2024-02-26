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
void Find(int* b, const int size, int i)
{
	if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
		b[i] = 0;
	if (i < size - 1)
		Find(b, size, i + 1);
}
int Sum(int* b, const int size, int i, int sum)
{
	if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
		sum += b[i];
	if (i < size - 1)
		return Sum(b, size, i + 1, sum);
	else
		return sum;
}
int Count(int* b, const int size, int i, int count)
{
	if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
		count++;
	if (i < size - 1)
		return Count(b, size, i + 1, count);
	else
		return count;
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 21;
	int b[n] ;
	
	int Low = 10;
	int High =90;
	Create(b, n, Low, High, 0);
	Print(b, n, 0);

	cout << Sum(b, n, 0, 0) << endl;
	cout << Count(b, n, 0, 0) << endl;
	Find(b, n, 0);
	Print(b, n, 0);

	return 0;
}