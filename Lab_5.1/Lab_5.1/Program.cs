//Lab 5_1
class Program
{
    static void Main(string[] args)
    {
        double s, t;
        Console.Write("a = "); s = double.Parse(Console.ReadLine());
        Console.Write("b = "); t = double.Parse(Console.ReadLine());
        double c = (F(1,t*t,s) + F(t,s*s,1))
              /(1 + F(1,t*s,1)*F(1, t * s, 1));
  
        Console.WriteLine("c = " + c);
    }
    static double F ( double a,  double b,  double c)
    {
        return Math.Sin(a*b*c) * Math.Sin(a * b * c)
               /(a*a + b*b + c*c);
    }
}