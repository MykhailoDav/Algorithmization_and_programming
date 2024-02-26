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
int Min(int* a, const int size)
{
	int min; 
	int imin = -1; 
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			min = a[i]; 
			imin = i; 
			break; 
		}
	if (imin == -1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0; 
	} 
	for (int i = imin + 1; i < size; i++)
		if (a[i] < min && a[i] % 2 != 0)
			min = a[i];
	return min;
}


template <typename T>  // шаблон функції
void Create(T* b, const int size, const T Low, const T High)
{
	for (int i = 0; i < size; i++)
		b[i] = Low + rand() % (High - Low + 1);
}
template <typename T>  // шаблон функції
void Print(T* b, const int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << setw(4) << b[i];
	cout << "]" << endl;
}
template <typename T>  // шаблон функції
T Min(T* a, const int size)
{
	T min;
	int imin = -1;
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			min = a[i];
			imin = i;
			break;
		}
	if (imin == -1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0;
	}
	for (int i = imin + 1; i < size; i++)
		if (a[i] < min && a[i] % 2 != 0)
			min = a[i];
	return min;
}


int main()
{
	srand((unsigned)time(NULL));
	//I спосіб
	const int n = 10;
	int b[n];
	int Low1 = 10;
	int High1 = 90;
	Create(b, n, Low1, High1);
	Print(b, n);
	cout << "min = " << Min(b, n) << endl;
	
	//II спосіб
	const int n1 = 10;
	int a[n1];
	int Low = 10;
	int High = 90;
	Create<int>(a, n1, Low, High);
	Print<int>(a, n1);
	cout << "min = " << Min<int>(a, n1) << endl;

	return 0;

}
