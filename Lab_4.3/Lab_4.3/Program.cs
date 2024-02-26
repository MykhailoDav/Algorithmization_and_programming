// Lab_04_3.cpp
// Давиденко Михайло
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами
// Варіант 7
double x; // вхідний аргумент 
double xp; // вхідний аргумент початковий
double xk; // вхідний аргумент кінцевий
double dx; // крок
double a; // вхідний параметр
double b; // вхідний параметр
double c; // вхідний параметр
double F; // результат обчислення виразу
Console.Write("a = "); a = double.Parse(Console.ReadLine());
Console.Write("b = "); b = double.Parse(Console.ReadLine());
Console.Write("c = "); c = double.Parse(Console.ReadLine());
Console.Write("xp = "); xp = double.Parse(Console.ReadLine());
Console.Write("xk = "); xk = double.Parse(Console.ReadLine());
Console.Write("dx = "); dx = double.Parse(Console.ReadLine());

int width = 24;
Console.WriteLine(new string('-', width));
Console.WriteLine("|" + "X".PadLeft(9) + "|" + "F".PadLeft(12) + "|");
Console.WriteLine(new string('-', width));

for (x = xp; x <= xk; x += dx)
{
    if (x < 5 && c != 0)
        F = -a * x * x - b;
    else if (x > 5 && c == 0)
        F = (x - a) / x;
    else
        F = -x / c;
    string xString = Convert.ToString(x);
    string FString = string.Format("{0:F2}", F);
    Console.WriteLine("|" + xString.PadLeft(9) + "|" + FString.PadLeft(12) + "|");

}
Console.WriteLine(new string('-', width));
Console.ReadLine();
