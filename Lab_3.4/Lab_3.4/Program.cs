// Lab_03_4.cpp
// Давиденко Михайло
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 7
double x; // вхідний аргумент
double y; // вхідний параметр
double R; // вхідний параметр

Console.WriteLine("R = "); R = double.Parse(Console.ReadLine());
Console.WriteLine("x = "); x = double.Parse(Console.ReadLine());
Console.WriteLine("y = "); y = double.Parse(Console.ReadLine());

// розгалуження в повній формі
if (((x + R) * (x + R) + (y - R) * (y - R) <= R * R)
    || (y >= R * (-1) && y <= 0 && x <= 2 * R) && x >= 0)
    Console.WriteLine("yes");
else
    Console.WriteLine("no");

Console.ReadLine();
