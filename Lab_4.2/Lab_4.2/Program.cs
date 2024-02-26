using System;

class Program
{
    static void Main()
    {
        double x, xp, xk, dx, A, B, y;
        Console.Write("xp = "); xp = double.Parse(Console.ReadLine());
        Console.Write("xk = "); xk = double.Parse(Console.ReadLine());
        Console.Write("dx = "); dx = double.Parse(Console.ReadLine());

        int width = 24;

        Console.WriteLine(new string('-', width));
        Console.WriteLine("|" + "X".PadLeft(9) + "|" + "Y".PadLeft(12) + "|");
        Console.WriteLine(new string('-', width));
        x = xp;
        while (x <= xk)
        {
            A = x * x * Math.Sin(x / 2);
            if (x <= 5)
                B = Math.Atan(Math.Exp(x));
            else if (x > -5 && x <= 0)
                B = 1.0 + (x * x * x) / 4;
            else
                B = Math.Log(Math.Abs(x)) - x / 5;
            y = A + B;
            string xString = string.Format("{0:F2}", x);
            string yString = string.Format("{0:F2}", y);
            Console.WriteLine("|" + xString.PadLeft(9) + "|" +
                               yString.PadLeft(12) + "|");
            x += dx;
        }
        Console.WriteLine(new string('-', width));
    }
}
