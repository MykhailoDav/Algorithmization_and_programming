#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		b[i] = Low + rand() % (High - Low + 1);
}
void Print(int* b, const int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << setw(4) << b[i];
	cout << "]" << endl;
}
void Find(int* b, const int size)
{
	for (int i = 0; i < size; i++)
		if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
			b[i] = 0;
}
int Sum(int* b, const int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
		sum += b[i];
	}
	return sum;
}
int Count(int* b, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)		
		if (!(b[i] % 2 != 0 && b[i] % 3 == 0))
		{
			count++;
		}	
	return count;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 21;
	int b[n];

	int Low = 10;
	int High = 90;
	Create(b, n, Low, High);
	Print(b, n);
	
	cout << Sum(b, n) << endl;
	cout << Count(b, n) << endl;
	Find(b, n);
	Print(b, n);

}
