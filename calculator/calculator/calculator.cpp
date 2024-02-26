#include <iostream> // підключаємо бібліотеку вводу-виводу
// - містить опис всіх функцій, які забезпечують ввід-вивід
#include <Windows.h> // підключаємо бібліотеку, яка забезпечує відображення кирилиці
using namespace std; // використовуємо стандартний простір імен
// - після цього доступ до ресурсів
// бібліотеки вводу-виводу буде не громіздкий, а компактний
int main() 
{	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
	double a;
	double b;
	double rez;
	char dia;
	cout << "a="; cin >> a;

	cout << "введіть дію (+ - * /) : "; cin >> dia;
	
	cout << "b="; cin >> b;
	
	switch (dia)
	{
	case '+' :
		rez = a + b;
		break;
	case '-':
		rez = a - b;
		break;
	case '*':
		rez = a * b;
		break;
	case '/':
		if (b != 0)
			rez = a / b;
		else
			cout << "на 0 ділити не можна" << endl;
		break;
	default:	
		cout << "Ви ввели не дійсну дію" << endl;
		break;
	}
	cout << "результат: " << rez << endl;
	return 0;
} 
