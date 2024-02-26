// Lab_04_4.cpp
// Давиденко Михайло
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком
// Варіант 7
double R;
double x;
double y;
double xp; 
double xk; 
double dx; 

Console.Write("R = "); R = double.Parse(Console.ReadLine());
Console.Write("xp = "); xp = double.Parse(Console.ReadLine());
Console.Write("xk = "); xk = double.Parse(Console.ReadLine());
Console.Write("dx = "); dx = double.Parse(Console.ReadLine());

int width = 24;
Console.WriteLine(new string('-', width));
Console.WriteLine("|" + "X".PadLeft(9) + "|" + "Y".PadLeft(12) + "|");
Console.WriteLine(new string('-', width));

for (x = xp; x <= xk; x += dx)
{
    if (x <= -R)
        y = R;
    else if (x >= -R && x <= R)
        y = R - Math.Sqrt(R * R - x * x);
    else if (x >= R && x <= 6)
        y = R + (-3 - R) / (6 - R) * (x - R);
    else
        y = x - 9;

    string xString = Convert.ToString(x);
    string yString = string.Format("{0:F2}", y);
    Console.WriteLine("|" + xString.PadLeft(9) + "|" + yString.PadLeft(12) + "|");

}
Console.WriteLine(new string('-', width));
Console.ReadLine();
