#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
	int n = 0;
	double Pi = 4 * atan(1.0);
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(12) << "arcctan(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	double arcctg;
	
	while (x <= xk)
	{
		n = 0; // вираз залежить від умови завдання в
		a = -x; // вираз залежить від умови завдання варіанту
		S = a;
		do {
			n++;
			R = -(2.0 * n - 1) * x * x / (2.0 * n + 1); // вираз залежить від умови завдання варіанту
			a *= R;
			S += a;
		} while (abs(a) >= eps);
		if (x > 0)
			arcctg = atan(1. / x);
		else 
			arcctg = Pi + atan(1 / x);
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << arcctg << " |"
			<< setw(10) << setprecision(5) << Pi / 2 + S << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	return 0;
}