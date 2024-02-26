// Lab_5.0


#include <iostream>
using namespace std;

double F(const double s, const double t, const double c);
       int main()
    {
        /*double s, t;
        cout<<"s = "; cin>>s;
        cout <<"t = "; cin>> t;
        cout << endl;
        double c = (F(1,t*t,s) + F(t,s*s,1))
               /(1 + F(1,t*s,1)*F(1, t * s, 1));*/
        double c = F(1, 1, 1);
        cout<<"c = " << c;
    }
     double F(const double a, const double b, const double c)
    {       
        return sin(a * b * c) * sin(a * b * c)
            / (a * a + b * b + c * c);
    }
