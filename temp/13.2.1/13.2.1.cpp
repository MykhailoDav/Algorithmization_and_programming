// Lab_13_2_1.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 13.2.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 29
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define Z 15 // директива препроцесора – макровизначення

#define SQR(x) (x)*(x) // макрос з параметром – визначення квадрата числа
#define SQR3(x) (x)*(x)*(x) // макрос з параметром – визначення куба числа

#define MAX(y,z) ((y)>(z))?(y):(z) 
#define MIN(y,z) ((y)<(z))?(y):(z) 

 // виведення повідомлення та значення цілого числа
#define PRINTI(w) puts("control output"); \
 printf(#w"=%d\n",w) 

 // виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts ("rezult :"); \
 printf (#w"=%f\n",(float)w)
void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, z; // змінні для розрахунків
	float rez;

#if Z<=5 	
	puts("Input 3 integer numbers");
	scanf("%d", &x);// введення числа
	PRINTI(x); // макрос виведення числа
	scanf("%d", &y);
	PRINTI(y);
	scanf("%d", &z);
	PRINTI(z);
	rez = MIN(x - y * z, x * y + z);
	PRINTR(rez);


#else

	puts("Input 3 integer numbers");
	scanf("%d", &x);// введення числа
	PRINTI(x); // макрос виведення числа
	scanf("%d", &y);
	PRINTI(y);
	scanf("%d", &z);
	PRINTI(z);

	rez = SQR(MAX(x * SQR3(y), x + z));

	PRINTR(rez);

#endif // завершення блоку умовної компіляції
}