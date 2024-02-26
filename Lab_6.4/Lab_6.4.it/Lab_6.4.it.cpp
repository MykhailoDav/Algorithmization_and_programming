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
	cout << "]\n" << endl;
}
int iMax(int* b, const int size)
{
	int max = b[0];
	int imax = 0;
	for (int i = 1; i < size; i++)
		if (b[i] > max)
		{
			max = b[i];
			imax = i;
		}
	return imax;
}

int FindFirstZeroIndex(int* b, int n) {
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			return i;
			break;
		}
	}
	return -1;
}
int FindSecondZeroIndex(int* b, int n, int startIndex) {
	for (int i = startIndex + 1; i < n; i++) {
		if (b[i] == 0) {
			return i;
			break;
		}
	}
	return -1;
}
int Product(int* b, int start, int end) {
	int product = 1;
	for (int i = start + 1; i < end; i++) {
		product *= b[i];
	}
	return product;
}

void oddElementsToTheLeft(int* b, int* a, const int size, int& j)
{

	for (int i = 1; i < size; i++)
	{
		if (i % 2 == 0)
		{			
			a[j] = b[i];	
			j++;
		}
	}
}
void evenElementsToTheRight(int* b, int* a, const int size, int& j)
{

	for (int i = 1; i < size; i++)
	{
		if (i % 2 != 0)
		{
			a[j] = b[i];
			j++;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	cout << "Enter number of element: ";
	int n;
	cin >> n;
	int* b = new int[n];
	int Low = -10;
	int High = 10;
	Create(b, n, Low, High);
	Print(b, n);

	cout << "Number of maximal element: " << (iMax(b, n) + 1) << "\n" << endl;

	int firstZeroIndex = FindFirstZeroIndex(b, n);
	int secondZeroIndex = FindSecondZeroIndex(b, n, firstZeroIndex);
	if (firstZeroIndex == -1) {
		cout << "Error: the first null element is not found." << endl;
	}
	else if (secondZeroIndex == -1) {
		cout << "Error: the second null element is not found." << endl;
	}
	else
	{
		int product = Product(b, firstZeroIndex, secondZeroIndex);
		cout << "The product of elements between the first and second zero elements: " << product << "\n" << endl;
	}

	int* a = new int[n];
	a[0] = b[0];
	int j = 1;
	oddElementsToTheLeft(b, a, n, j);
	evenElementsToTheRight(b, a, n, j);
	b = a;
	Print(b, n);
	delete[] a;

	return 0;
}
