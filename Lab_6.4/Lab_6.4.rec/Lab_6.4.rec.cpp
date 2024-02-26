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
int iMaxRecursive(int* b, const int size, int i, int max, int imax)
{
	if (i < size) {
		if (b[i] > max) {
			max = b[i];
			imax = i;
		}
		return iMaxRecursive(b, size, i + 1, max, imax);
	}
	return imax;
}
int FindFirstZeroIndexRecursive(int* b, int n, int i)
{
	if (i < n) {
		if (b[i] == 0) {
			return i;
		}
		return FindFirstZeroIndexRecursive(b, n, i + 1);
	}
	return -1;
}
int FindSecondZeroIndexRecursive(int* b, int n, int startIndex, int i)
{
	if (i < n) {
		if (i > startIndex && b[i] == 0) {
			return i;
		}
		return FindSecondZeroIndexRecursive(b, n, startIndex, i + 1);
	}
	return -1;
}
int ProductRecursive(int* b, int start, int end, int i, int product)
{
	if (i > start && i < end) {
		product *= b[i];
		return ProductRecursive(b, start, end, i + 1, product);
	}
	return product;
}
void oddElementsToTheLeftRecursive(int* b, int* a, const int size, int i, int j)
{
	if (i < size) {
		if (i % 2 == 0) {
			a[j] = b[i];
			oddElementsToTheLeftRecursive(b, a, size, i + 1, j + 1);
		}
		else {
			oddElementsToTheLeftRecursive(b, a, size, i + 1, j);
		}
	}
}
void evenElementsToTheRightRecursive(int* b, int* a, const int size, int i, int j)
{
	if (i < size) {
		if (i % 2 != 0) {
			a[j] = b[i];
			evenElementsToTheRightRecursive(b, a, size, i + 1, j + 1);
		}
		else {
			evenElementsToTheRightRecursive(b, a, size, i + 1, j);
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
	Create(b, n, Low, High,0);
	Print(b, n, 0);

	int maxIndex = iMaxRecursive(b, n, 1, b[0], 0);
	cout << "Number of maximal element: " << (maxIndex + 1) << "\n" << endl;

	int firstZeroIndex = FindFirstZeroIndexRecursive(b, n, 0);
	int secondZeroIndex = FindSecondZeroIndexRecursive(b, n, firstZeroIndex, firstZeroIndex + 1);

	if (firstZeroIndex == -1) {
		cout << "Error: the first null element is not found." << endl;
	}
	else if (secondZeroIndex == -1) {
		cout << "Error: the second null element is not found." << endl;
	}
	else
	{
		int product = ProductRecursive(b, firstZeroIndex, secondZeroIndex, firstZeroIndex + 1, 1);
		cout << "The product of elements between the first and second zero elements: " << product << "\n" << endl;
	}

	int* a = new int[n];
	a[0] = b[0];
	int j = 1;
	oddElementsToTheLeftRecursive(b, a, n, 1, j);
	if (n % 2 == 0)
		j = n / 2;
	else
		j = n / 2 + 1;
	evenElementsToTheRightRecursive(b, a, n, 1, j);
	b = a;
	Print(b, n, 0);
	delete[] a;

	return 0;
}
