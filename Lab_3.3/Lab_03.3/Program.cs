// Lab_03_3.cpp
// Давиденко Михайло
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 7
double y;
Console.WriteLine("Введіть значення R: ");
double R = double.Parse(Console.ReadLine());
Console.WriteLine("Введіть значення x: ");
double x = double.Parse(Console.ReadLine());
if (x <= -R)
    y = R;
else if (x >= -R && x <= R)
    y = R - Math.Sqrt(R * R - x * x);
else if (x >= R && x <= 6)
    y = R + (-3 - R) / (6 - R) * (x - R);
else
    y = x-9;
Console.WriteLine("y = "+y);