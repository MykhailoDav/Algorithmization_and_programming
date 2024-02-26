#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define Z 2 // директива препроцесора – макровизначення
#define SQR(x) (x)*(x) // макрос з параметром – визначення квадрата числа
#define PRODUCT(a,b) (a)*(b)// макрос з параметром – визначення добутку
// макрос визначення найбільшого з двох чисел
#define MAX(y,z) ((y)>(z))?(y):(z) 
// макрос як умовний вираз
 // виведення повідомлення та значення цілого числа
#define PRINTI(w) puts("control output"); \
 printf(#w"=%d\n",w) 
 // використовується символ продовження макроса '\'
// символ '#' використовується для об’єднання рядків
 // виведення повідомлення та значення дійсного числа
#define PRINTR(w)  printf (#w"=%f\n",(float)w)

void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, z, // змінні для розрахунків	
		rezult_1, rezult_2; // максимальне з трьох чисел
	char ch; // відповідь чи продовжувати виконання програми
	
		puts("Input 3 integer numbers");
		scanf("%d", &x);// введення числа
		PRINTI(x); // макрос виведення числа
		scanf("%d", &y);
		PRINTI(y);
		scanf("%d", &z);
		PRINTI(z);
#if Z>3
		{
			rezult_1 = MAX(SQR(x - z), (x - y));
			PRINTR(rezult_1);
		}
#else
		{
			rezult_2 = (MAX(PRODUCT(x, y), PRODUCT(y, z))) + (MAX(PRODUCT(z, x), PRODUCT(y, z)));
			PRINTR(rezult_2);
		}
#endif // завершення блоку умовної компіляції
		puts("Repeat? y /n "); ch = _getch();

}
