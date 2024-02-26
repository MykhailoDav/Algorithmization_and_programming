#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
using namespace std;

int Count(char* s) {
    int k = 0, pos = 0;
    char* t;
    while (t = strstr(s + pos, "while"))// вказівник на позицію входження "while" в рядок s
    { 
        pos = t - s + 1;
        k++;
    }
    return k;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 3]; 
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;
    while (p = strstr(s + pos1, "while"))// вказівник на позицію входження "while" в рядок p
    {
        pos2 = p - s + 5;
        strncat(t, s + pos1, pos2 - pos1 - 5);//добавляє не більше n символів рядка s2 в рядок s1
        strcat(t, "***");//до кінця першого аргументу приєднує другий
        pos1 = pos2;
    }
    strcat(t, s + pos1);//до кінця першого аргументу приєднує другий
    strcpy(s, t);//поєднати початок першого рядка та закінчення другого
    return t;
}

int main() {
    cout << "char:" << endl;
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " occurrences of 'while'" << endl;
    char* dest = new char[strlen(str) * 3];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest; 
    return 0;
}
