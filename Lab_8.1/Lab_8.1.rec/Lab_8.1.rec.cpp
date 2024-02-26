#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str, int i) 
{
    if (strlen(str) < 5)
        return 0;
    if (str[i + 4] != 0) 
    {
        if (strncmp(str + i, "while", 5) == 0)//порівнює до n символів рядків s1 та s2
            return 1 + Count(str, i + 5);
        else
            return Count(str, i + 1);
    }
    else 
    {
        return 0;
    }
}

char* Change(char* dest, const char* str, char* t, int i) 
{
    if (str[i + 4] != 0)
    {
        if (strncmp(str + i, "while", 5) == 0) //порівнює до n символів рядків s1 та s2
        {
            strcat(t, "***");//до кінця першого аргументу приєднує другий
            return Change(dest, str, t + 3, i + 5);
        }
        else 
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

int main() {
    cout << "rec:" << endl;
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str, 0) << " occurrences of 'while'" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1; // Видаляємо виділену пам'ять
    return 0;
}
