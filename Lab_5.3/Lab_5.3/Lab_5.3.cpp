#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double k(const double x);

int main()
{
	double zp, zk,rez;
	int n;
	cout << "zp = "; cin >> zp;
	cout << "zk = "; cin >> zk;
	cout << "n = "; cin >> n;
	double z_step = (zk - zp) / n;
	double z = zp;

	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "z" << " |"
		<< setw(10) << "REZ" << " |" << endl;
	cout << "----------------------" << endl;


	while (z <= zk)
	{
		rez = k(z*z+1)-k(z*z-1)+2*k(z);
		
		cout <<"|" << setw(7) << setprecision(2) << z << " |"
			<< setw(10) << setprecision(5) << rez <<" |" << endl;
		z += z_step;
	}
	cout << "----------------------" << endl;
	
	return 0;
}
double k(const double x)
{
	if (abs(x) >= 1)
		return (exp(x) + sin(x)) / (cos(x)* cos(x) + 1);
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = x/i;			
			a *= R;
			S += a;
		} while (i < 5);
		return (1./ exp(x))*S;
	}
}





