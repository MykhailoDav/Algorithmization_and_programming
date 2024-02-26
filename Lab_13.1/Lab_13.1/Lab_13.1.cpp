#include <iostream>
#include <math.h>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"
#include "round.h"
using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;
using namespace nsRoundToNDigits;

int main()
{
	double Pi = 4 * atan(1.0);
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx = "; cin >> dx;
	cout << "e = "; cin >> e;
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(12) << "arcctan(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = x_p;
	while (x <= x_k)
	{

		sum(); // виклик процедури обчислення суми
		if (x < 0)
			arcctg = Pi + atan(1 / x);
		else if (x == 0)
			arcctg = Pi;
		else if (x > 0)
			arcctg = atan(1. / x);

		cout << "|" << setw(7) << (roundToNDigits()) << " |"
			<< setw(10) << setprecision(5) << arcctg << " |"
			<< setw(10) << setprecision(5) << Pi / 2 + s << " |"
			<< setw(5) << n << " |"
			<< endl; // тут слід використовувати форматний вивід
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	cin.get();
	return 0;
}
