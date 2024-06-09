// Lab_13_2_1.cpp
// < �������, ��� ������ >
// ����������� ������ � 13.2.1
// ������������, ������ ��������: ������� ���� �����.
// ������ 29
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#define Z 15 // ��������� ������������ � ���������������

#define SQR(x) (x)*(x) // ������ � ���������� � ���������� �������� �����
#define SQR3(x) (x)*(x)*(x) // ������ � ���������� � ���������� ���� �����

#define MAX(y,z) ((y)>(z))?(y):(z) 
#define MIN(y,z) ((y)<(z))?(y):(z) 

 // ��������� ����������� �� �������� ������ �����
#define PRINTI(w) puts("control output"); \
 printf(#w"=%d\n",w) 

 // ��������� ����������� �� �������� ������� �����
#define PRINTR(w) puts ("rezult :"); \
 printf (#w"=%f\n",(float)w)
void main()
{
	puts("Lab 13.2. Using macros and preprocessing directive");
	int x, y, z; // ���� ��� ����������
	float rez;

#if Z<=5 	
	puts("Input 3 integer numbers");
	scanf("%d", &x);// �������� �����
	PRINTI(x); // ������ ��������� �����
	scanf("%d", &y);
	PRINTI(y);
	scanf("%d", &z);
	PRINTI(z);
	rez = MIN(x - y * z, x * y + z);
	PRINTR(rez);


#else

	puts("Input 3 integer numbers");
	scanf("%d", &x);// �������� �����
	PRINTI(x); // ������ ��������� �����
	scanf("%d", &y);
	PRINTI(y);
	scanf("%d", &z);
	PRINTI(z);

	rez = SQR(MAX(x * SQR3(y), x + z));

	PRINTR(rez);

#endif // ���������� ����� ������ ���������
}