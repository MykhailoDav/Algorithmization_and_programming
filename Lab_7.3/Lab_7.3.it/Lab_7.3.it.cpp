// Lab_7.3.cpp 
#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << "k" << i + 1 << " = " << a[i] << endl;
	cout << endl;
}
void if_K_equal_K(int** a, const int n, int* K, int& count)
{
	for (int k = 0; k < n; k++)
	{
		bool areEqual = true;
		for (int i = 0; i < n; i++)
		{
			if (a[k][i] != a[i][k])
				areEqual = false;
		}
		if (areEqual == true)
		{
			K[count] = (k + 1);
			count++;
		}
	}
}
int sumOfRowsWithNegative(int** a, const int n, int& ifNegative)
{
	int sum = 0;

	for (int i = 0; i < n; i++) {
		bool hasNegative = false;
		for (int j = 0; j < n; j++)
			if (a[i][j] < 0) {
				hasNegative = true;
				break; // Якщо знайдено від'ємний елемент, перервемо цикл
			}

		if (hasNegative) {
			ifNegative++;
			for (int j = 0; j < n; j++) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}
int main()
{
	int n;
	cout << "Enter size of matrix: "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Input(a, n);
	cout << "You matrix: " << endl;
	Print(a, n);

	int* K = new int[n];
	int count = 0;

	if_K_equal_K(a, n, K, count);
	if (count != 0)
		print(K, count);
	else
		cout << "Error: k is missing" << endl;

	int ifNegative = 0;
	int sum = sumOfRowsWithNegative(a, n, ifNegative);
	if (ifNegative == 0)
		cout << "Error: no negative elements";
	else
		cout << "Sum of element which rows have negative value: " << sum << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}