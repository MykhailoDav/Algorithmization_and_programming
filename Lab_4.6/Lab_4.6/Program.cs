// Lab_04_6.cpp
// Давиденко Михайло
// Лабораторна робота № 4.6
// Вкладені цикли
// Варіант 7

double P, S;
    int k, i;
    P = 1;
    k = 1;

    while (k <= 20)
    {
        S = 0;
        i = 1;
        while (i <= k)
        {
            S += i*i;
            i++;
        }
        P *= S / (1 + S);
        k++;
    }
Console.WriteLine(P);

    P = 1;
    k = 1;
    do
    {
     S = 0;
     i = 1;
        do
        {
        S += i * i;
        i++;
        } 
        while (i <= k);
        P *= S / (1 + S);
        k++;
    } while (k <= 20);
Console.WriteLine(P);
P = 1;
    for (k = 1; k <= 20; k++)

    {
        S = 0;
        for (i = 1; i <= k; i++)

        {
        S += i * i;

    }
    P *= S / (1 + S);

}
Console.WriteLine(P);
P = 1;
    for (k = 20; k >= 1; k--)

    {
        S = 0;
        for (i = k; i >= 1; i--)

        {
        S += i * i;
        
        }
         P *= S / (1 + S);
}
Console.WriteLine(P);

