// Lab_08_1_it.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 8.1_it
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 29
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

bool IfFourSameIs(char* str)
{
	bool f = 0;
	size_t len = strlen(str);
	if (strlen(str) < 5)//обчислює довжину рядка
		return 0;	
	for (int i = 0; str[i + 3] != 0; i++)
	{
		if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3])
		{
			f = 1;
			break;
		}
	}
	return f;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 4)
		return str;

	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	int i = 0;

	while (i < len && i + 3 < len)
	{
		if (str[i] == str[i + 1] && str[i + 1] == str[i + 2] && str[i + 2] == str[i + 3])
		{
			strcat(t, "**");
			t += 2;
			i += 4;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	delete[] tmp;
	return str;
}
int main()
{
	std::cout << "it:" << std::endl;
	char str[101];
	std::cout << "Enter string:" << std::endl;
	std::cin.getline(str, 100);

	if (IfFourSameIs(str))
	{
		std::cout << "Yes" << std::endl;
		char* dest = Change(str);
		std::cout << "Modified string (param) : " << str << std::endl;
		std::cout << "Modified string (result): " << dest << std::endl;
	}
	else
		std::cout << "No" << std::endl;

	return 0;
}
