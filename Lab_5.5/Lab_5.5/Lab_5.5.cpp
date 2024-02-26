#include <iostream>
#include <string>
#include <Windows.h> // підключаємо бібліотеку, яка забезпечує відображення кирилиці
using namespace std; 
 


// Функція для перетворення числа у двійкову систему числення
string toBinary(int num, int level, int& depth) {
    if (level > depth)
        depth = level;
    cout <<  "Рівень: " << level << endl;
    if (num == 0) {
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else {
        int remainder = num % 2;
        return toBinary(num / 2, level + 1, depth) + to_string(remainder);
    }
}

// Функція для перетворення числа у вісімкову систему числення
string toOctal(int num, int level, int& depth) {
    if (level > depth)
        depth = level;
    cout  <<"Рівень: " << level << endl;
    if (num < 8) {
        return to_string(num);
    }
    else {
        int remainder = num % 8;
        return toOctal(num / 8, level + 1, depth) + to_string(remainder);
    }
}

// Функція для перетворення числа у систему числення з основою N
string toBaseN(int num, int base, int level, int& depth) {
    if (level > depth)
        depth = level;
    cout  << "Рівень: " << level << endl;
    if (num < base) {
        return to_string(num);
    }
    else {
        int remainder = num % base;
        return toBaseN(num / base, base, level + 1, depth) + to_string(remainder);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int decimalNumber;
    cout << "Введіть натуральне число у десятковій системі числення: ";
    cin >> decimalNumber;
    int depth = 0;

    // Перетворення у двійкову систему числення
    string binary = toBinary(decimalNumber, 1, depth);
    cout << "Двійкове представлення: " << binary << endl;
    cout << "Глибина функції = " << depth <<"\n" << endl;

    // Перетворення у вісімкову систему числення
    depth = 0;
   string octal = toOctal(decimalNumber, 1, depth);
   cout << "Вісімкове представлення: " << octal << endl;
   cout << "Глибина функції = " << depth << "\n" << endl;

    // Перетворення у систему числення з основою N (наприклад, N = 5)
   depth = 0;
    int baseN;
    cout << "Введіть основу N для системи числення: ";
    cin >> baseN;

    string baseNRepresentation = toBaseN(decimalNumber, baseN, 1, depth);
   cout << "Представлення в системі з основою " << baseN << ": " << baseNRepresentation << endl;
   cout << "Глибина функції = " << depth << "\n" << endl;
    return 0;
}
