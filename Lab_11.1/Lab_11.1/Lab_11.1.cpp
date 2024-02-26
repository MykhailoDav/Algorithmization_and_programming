#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h> // підключаємо бібліотеку, яка забезпечує відображення кирилиці
using namespace std;

// Функція для генерації та запису різних дійсних чисел у бінарний файл
void generateAndWriteBinaryFile(const string filename, int count)
{
	ofstream file(filename, ios::binary);

	if (!file.is_open())
	{
		cerr << "Error opening file." << endl;
		return;
	}

	// Встановлення генератора випадкових чисел на основі поточного часу
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < count; ++i)
	{
		// Генерація випадкового дійсного числа в діапазоні від -100.0 до 100.0
		double randomNumber = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;

		// Запис дійсного числа у файл
		file.write(reinterpret_cast<const char*>(&randomNumber), sizeof(double));
	}

	file.close();
}

// Функція, яка перевіряє, чи може число бути значенням exp(x)
bool isValidExpValue(double num)
{
	return num >= 0.0;
}

// Функція для копіювання в інший файл тих компонент, які можуть бути значеннями exp(x)
void copyExpValues(const string inputFilename, const string outputFilename)
{
	ifstream inputFile(inputFilename, ios::binary);
	ofstream outputFile(outputFilename, ios::binary);

	if (!inputFile.is_open() || !outputFile.is_open())
	{
		cerr << "Error opening files." << endl;
		return;
	}

	double num;
	while (inputFile.read((char*)&num, sizeof(double)))
	{
		if (isValidExpValue(num))
		{
			outputFile.write((char*)&num, sizeof(double));
		}
	}

	inputFile.close();
	outputFile.close();
}

// Функція для виведення вмісту файлу на екран
void displayFileContent(const string filename)
{
	ifstream file(filename, ios::binary);

	if (!file.is_open())
	{
		cerr << "Error opening file." << endl;
		return;
	}

	cout << "File content:" << endl;
	double num;
	while (file.read(reinterpret_cast<char*>(&num), sizeof(double)))
	{
		cout << fixed << setprecision(3) << num << endl;
	}

	file.close();
}

int main()
{
	SetConsoleCP(1251); // встановлення кодової сторінки win-cp1251
	// (кирилиця) в потік вводу
	SetConsoleOutputCP(1251); // встановлення кодової сторінки win-cp1251
	// (кирилиця) в потік виводу

	string fileName;
	cin >> fileName;
	const string dataFileName = fileName;
	const int numberOfValues = 10;

	// Генерація та запис дійсних чисел у бінарний файл
	generateAndWriteBinaryFile(dataFileName, numberOfValues);

	const string expValuesFileName = "exp_values.dat";
	// Виведення вмісту результатуючого файлу
	displayFileContent(dataFileName);

	// Копіювання можливих значень exp(x) в інший файл
	copyExpValues(dataFileName, expValuesFileName);
	cout << endl <<"компоненти, які можуть бути значеннями функції exp x:" << endl;
	// Виведення вмісту результатуючого файлу
	displayFileContent(expValuesFileName);

	return 0;
}
