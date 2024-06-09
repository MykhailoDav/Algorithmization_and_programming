// Lab_11_1.cpp
// < �������, ��� ������ >
// ����������� ������ � 11.1
// ������������, ������ ��������: ������� ���� �����.
// ������ 29
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h> // ��������� ��������, ��� ��������� ����������� ��������
using namespace std;

// ������� ��� ��������� �� ������ ����� ������ ����� � ������� ����
void generateAndWriteBinaryFile(const string filename, int count)
{
	ofstream file(filename, ios::binary);

	if (!file.is_open())
	{
		cerr << "Error opening file." << endl;
		return;
	}

	// ������������ ���������� ���������� ����� �� ����� ��������� ����
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < count; ++i)
	{
		// ��������� ����������� ������� ����� � ������� �� -100.0 �� 100.0
		double randomNumber = static_cast<double>(rand()) / RAND_MAX * 200.0 - 100.0;

		// ����� ������� ����� � ����
		file.write(reinterpret_cast<const char*>(&randomNumber), sizeof(double));
	}

	file.close();
}

// �������, ��� ��������, �� ���� ����� ���� ��������� lg(x)
bool isValidLgArg(double num)
{
	return num > 0.0;
}

// ������� ��� ��������� � ����� ���� ��� ���������, �� ������ ���� ���������� exp(x)
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
		if (isValidLgArg(num))
		{
			outputFile.write((char*)&num, sizeof(double));
		}
	}

	inputFile.close();
	outputFile.close();
}

// ������� ��� ��������� ����� ����� �� �����
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
	SetConsoleCP(1251); // ������������ ������ ������� win-cp1251
	// (��������) � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������ ������� win-cp1251
	// (��������) � ���� ������

	string fileName;
	cout << "enter name of binar file" << endl;
	cin >> fileName;
	const string dataFileName = fileName;
	const int numberOfValues = 10;

	// ��������� �� ����� ������ ����� � ������� ����
	generateAndWriteBinaryFile(dataFileName, numberOfValues);

	const string expValuesFileName = "exp_values.dat";
	// ��������� ����� ��������������� �����
	displayFileContent(dataFileName);

	// ��������� �������� ������� exp(x) � ����� ����
	copyExpValues(dataFileName, expValuesFileName);
	cout << endl << "����������, �� ������ ���� ���������� ������� exp x:" << endl;
	// ��������� ����� ��������������� �����
	displayFileContent(expValuesFileName);

	return 0;
}
