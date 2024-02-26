// Lab_04.1.cpp
// Давиденко Михайло
// Лабораторна робота № 4.1
// Цикли
// Варіант 7

int k, N;
double S;

Console.WriteLine("N= "); N = int.Parse(Console.ReadLine());
S = 0;
k = 1;
while (k <= N)
{
    S += 1.0 / ((2 * k + 1) * (2 * k + 1));
    k++;
}
Console.WriteLine(S);

S = 0;
k = 1;
do
{
    S += 1.0 / ((2 * k + 1) * (2 * k + 1));
    k++;
} while (k <= N);
Console.WriteLine(S);

S = 0;
for (k = 1; k <= N; k++)
    S += 1.0 / ((2 * k + 1) * (2 * k + 1));
Console.WriteLine(S);

S = 0;
for (k = N; k >=1; k--)
    S += 1.0 / ((2 * k + 1) * (2 * k + 1));
Console.WriteLine(S);
Console.ReadLine();