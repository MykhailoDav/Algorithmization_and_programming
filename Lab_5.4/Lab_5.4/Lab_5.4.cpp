// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int N)
{
	double s = 0;
	for (int k = 1; k <= N; k++)
		s += 1.0 / ((2 * k + 1) * (2 * k + 1));
	return s;
}
double S1(const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return 1.0 / ((2 * k + 1) * (2 * k + 1)) + S1(N, k + 1);
}
double S2(const int N, const int k)
{
	if (N < k)
		return 0;
	else
		return 1.0 / ((2 * N + 1) * (2 * N + 1)) + S2(N - 1, k);
}

double S3(const int N, const int k, double t)
{
	t = t + 1.0 / ((2 * k + 1) * (2 * k + 1));
	if (k >= N)
		return t;
	else
		return S3(N, k + 1, t);
}
double S4(const int N, const int k, double t)
{
	t = t + 1.0 / ((2 * N + 1) * (2 * N + 1));
	if (N <= k)
		return t;
	else
		return S4(N - 1, k, t);
}
int main()
{
	int k = 1, N;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(N) << endl;
	cout << "(rec up ++) S1 = " << S1(N, k) << endl;
	cout << "(rec up --) S2 = " << S2(N, k) << endl;
	cout << "(rec down ++) S3 = " << S3(N, k, 0) << endl;
	cout << "(rec down --) S4 = " << S4(N, k, 0) << endl;
	return 0;
}
