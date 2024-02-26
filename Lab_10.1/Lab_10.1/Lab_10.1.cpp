#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Count(const string s) {
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != -1)//повертає позицію першого входження символу
    {
        pos += 5;
        k++;
    }
    return k;
}

int CountInFile(const string t) {
    ifstream file(t);// файл, який можна лише читати
    if (!file.is_open()) //перевірка чи відкритий файл
    {
        cerr << "Error opening file." << endl;
        return -1;
    }

    string line;
    string content;
    while (getline(file, line)) {
        content += line + "\n";
    }

    file.close();

    return Count(content);
}

int main() {
    

    int result = CountInFile("t.txt");

    if (result != -1) {
        cout << "File contained " << result << " groups of 'while'" << endl;
    }

    return 0;
}