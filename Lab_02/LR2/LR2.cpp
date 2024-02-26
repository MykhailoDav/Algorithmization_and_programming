// Lab_02.cpp
// Давиденко Михайло
// Лабораторна робота № 2.
// Лінійні програми.
// Варіант 7
#include <iostream>
using namespace std;
int main()
{
	double Pi = 4 * atan(1.); // число пі
	double a; // вхідний параметр
	double z1; // результат обчислення 1-го виразу
	double z2; // результат обчислення 2-го виразу  

	cout << "a = "; cin >> a;

	z1 = cos(3 * Pi / 8 - a / 4) * cos(3 * Pi / 8 - a / 4) -
		cos(11 * Pi / 8 + a / 4) * cos(11 * Pi / 8 + a / 4);

	z2 = sqrt(2) / 2 * sin(a / 2);

	cout << endl;
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cin.get();
	return 0;
}