//Hello while true while cool!
//fucowvho3ub while vbqvpicb while vfw158 while vbwv3;nieb;while !!!
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str)
{
	if (strlen(str) < 5)//обчислює довжину рядка
		return 0;

	int k = 0;
	for (int i = 1; str[i + 3] != 0; i++)
	{
		if (strncmp(str + i - 1, "while", 5) == 0)//порівнює до n символів рядків s1 та s2
		{
			k++;
		}
	}
	return k;
}

char* Change(char* str)
{
	size_t len = strlen(str);//обчислює довжину рядка
	if (len < 5)
		return str;

	char* tmp = new char[len * 4 / 3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;

	while (i < len && str[i + 4] != 0)
	{
		if (strncmp(str + i, "while", 5) == 0)//порівнює до n символів рядків s1 та s2
		{
			strcat(t, "***");//до кінця першого аргументу приєднує другий
			t += 3;
			i += 5;
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
	return tmp;
}

int main()
{
	cout << "it:" << endl;
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " occurrences of 'while'" << endl;
	//вказівник на динамічний масив символів
	char* dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	delete[] dest;
	return 0;
}