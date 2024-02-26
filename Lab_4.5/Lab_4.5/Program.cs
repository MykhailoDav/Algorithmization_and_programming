// Lab_04_5.cpp
// Давиденко Михайло
// Лабораторна робота № 3.4
// Попадання» у плоску фігуру
// Варіант 7
double x; 
double y; 
int R; 


Console.Write("R = "); R = int.Parse(Console.ReadLine());

Random random = new Random();

for (int i = 0; i < 10; i++)
{
    Console.WriteLine("\n" + (i+1) + ")");
    Console.Write("x = "); x = double.Parse(Console.ReadLine());
    Console.Write("y = "); y = double.Parse(Console.ReadLine());

    if (((x + R) * (x + R) + (y - R) * (y - R) <= R * R)
    || (y >= R * (-1) && y <= 0 && x <= 2 * R) && x >= 0)
        Console.WriteLine("yes");
    else
        Console.WriteLine("no");
}
Console.ReadLine();

int width = 25;
Console.WriteLine(new string('-', width));

for (int i = 0; i < 10; i++)
{
    double randomX = random.NextDouble() * (2*R - (-2*R)) + (-2*R);
    double randomY = random.NextDouble() * (2*R - (-2*R)) + (-2*R);

    string random_X_String = string.Format("{0:F4}", randomX);
    string random_Y_String = string.Format("{0:F4}", randomY);

    if (((randomX + R) * (randomX + R) + (randomY - R) * (randomY - R) <= R * R)
    || (randomY >= R * (-1) && randomY <= 0 && randomX <= 2 * R) && randomX >= 0)

        Console.WriteLine("|" + random_X_String.PadLeft(8) + "|" + random_Y_String.PadLeft(8) + "|" + " yes |");
    
    else
        Console.WriteLine("|" + random_X_String.PadLeft(8) + "|" + random_Y_String.PadLeft(8) + "|" + " no  |");
    

}

Console.WriteLine(new string('-', width));


