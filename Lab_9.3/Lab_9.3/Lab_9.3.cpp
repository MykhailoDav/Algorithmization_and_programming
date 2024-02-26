#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Product {
	string name;
	string storeName;
	double priceUAN;
	double amount;
	string unitMeasurement;
};

void printProducts(const Product* p, const int N);
void printProductRow(int number, const Product& product);
void createProducts(Product* p, const int N);
void editProduct(Product& product);
void sortProductsByName(Product* p, const int N);
void sortProductsByStore(Product* p, const int N);
void displayProductInfoByName(const Product* p, const int N, const string& productName);
void displayProductsByStore(const Product* p, const int N, const string& storeName);
void Remove(Product*& p, int k, int& N);
void AddItem(Product*& p, int k, int& N);
void SaveToFile(Product* p, const int N, const char* filename);
void LoadFromFile(Product*& p, int& N, const char* filename);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Product* p = new Product[N];

	createProducts(p, N);
	char filename[100];

	while (true) {
		cout << "Оберіть дію:" << endl;
		cout << "1. Редагувати товар" << endl;
		cout << "2. Вивести інформацію про всі товари" << endl;
		cout << "3. Вивести інформацію про товар за його назвою" << endl;
		cout << "4. Вивести інформацію про товари в магазині" << endl;
		cout << "5. Сортувати за назвою товару" << endl;
		cout << "6. Сортувати за назвою магазину" << endl;
		cout << "7. Видалити товар" << endl;
		cout << "8. Добавити товар" << endl;
		cout << "9. запис даних у файл" << endl;
		cout << "10.зчитування даних із файлу" << endl;
		cout << "0. Вийти" << endl;
		cout << endl;

		int choice;
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			int e;
			cout << "Який елемент ви хочете змінити?" << endl;
			cin >> e;
			cout << endl;
			e--;
			cout << "Редагування товару:" << endl;
			printProductRow(e + 1, p[e]);
			editProduct(p[e]);
			break;
		case 2:
			printProducts(p, N);
			cout << endl;
			break;
		case 3: {
			string productName;
			cout << "Введіть назву товару: ";
			cin.ignore();
			getline(cin, productName);
			cout << endl;
			displayProductInfoByName(p, N, productName);
		} break;
		case 4: {
			string storeName;
			cout << "Введіть назву магазину: ";
			cin.ignore();
			getline(cin, storeName);
			cout << endl;
			displayProductsByStore(p, N, storeName);
		} break;
		case 5:
			sortProductsByName(p, N);
			cout << endl;
			printProducts(p, N);
			cout << endl;
			break;
		case 6:
			sortProductsByStore(p, N);
			cout << endl;
			printProducts(p, N);
			cout << endl;
			break;
		case 7:
			int k;
			cout << "Який елемент ви хочете видалити?" << endl;
			cin >> k;
			cout << endl;
			k--;
			Remove(p, k, N);
			break;
		case 8:
			int w;
			cout << "В яку позицію ви хочете добавити елемент?" << endl;
			cin >> w;
			cout << endl;
			w--;
			AddItem(p, w, N);
			break;
		case 9:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 10:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			cout << "Дякуємо за використання програми. До побачення!" << endl;
			exit(0);
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	}

	return 0;
}
void printProducts(const Product* p, const int N) {
	cout << "===============================================================================" << endl;
	cout << "| № |    Назва    |  Магазин   | Ціна (грн) | Кількість | Одиниця вимірювання |" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {
		printProductRow(i + 1, p[i]);
		// Виведення роздільника між рядками
		if (i != N - 1) {
			cout << "-------------------------------------------------------------------------------" << endl;
		}
	}

	cout << "===============================================================================" << endl;
	cout << endl;
}
void printProductRow(int number, const Product& product) {
	cout << "| " << setw(1) << right << number << " ";
	cout << "| " << setw(12) << left << product.name
		<< "| " << setw(11) << left << product.storeName
		<< "| " << setw(10) << setprecision(2) << fixed << right << product.priceUAN
		<< " | " << setw(9) << right << product.amount
		<< " | " << setw(19) << left << product.unitMeasurement << " |" << endl;
}
void createProducts(Product* p, const int N) {
	for (int i = 0; i < N; i++) {
		cout << "Товар № " << i + 1 << ":" << endl;
		cin.ignore();
		cin.sync();

		cout << " Назва: "; getline(cin, p[i].name);
		cout << " Магазин: "; getline(cin, p[i].storeName);
		cout << " Ціна за одиницю: "; cin >> p[i].priceUAN;
		cout << " Кількість: "; cin >> p[i].amount;
		cout << " Одиниця вимірювання: "; cin.ignore(); getline(cin, p[i].unitMeasurement);

		cout << endl;
	}
}
void editProduct(Product& product) {
	cout << " Назва: "; cin.ignore(); getline(cin, product.name);
	cout << " Магазин: "; getline(cin, product.storeName);
	cout << " Ціна за одиницю: "; cin >> product.priceUAN;
	cout << " Кількість: "; cin >> product.amount; cin.ignore();
	cout << " Одиниця вимірювання: "; getline(cin, product.unitMeasurement);
}
void sortProductsByName(Product* p, const int N) {
	Product tmp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			// Порівнюємо за назвою (name)
			if (p[j].name > p[j + 1].name) {
				// Обмін елементів, якщо потрібно
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
void sortProductsByStore(Product* p, const int N) {
	Product tmp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (p[j].storeName > p[j + 1].storeName) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
void displayProductInfoByName(const Product* p, const int N, const string& productName) {
	int foundIndex = -1;

	for (int i = 0; i < N; i++) {
		if (p[i].name == productName) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {
		printProducts(p + foundIndex, 1);
	}
	else {
		cout << "Товар з назвою \"" << productName << "\" не знайдено." << endl;
	}
}
void displayProductsByStore(const Product* p, const int N, const string& storeName) {
	bool foundAny = false;

	for (int i = 0; i < N; i++) {
		if (p[i].storeName == storeName) {
			if (!foundAny) {
				cout << "Товари в магазині \"" << storeName << "\":" << endl;
				foundAny = true;
			}
			printProducts(p + i, 1);
		}
	}

	if (!foundAny) {
		cout << "Товарів у магазині \"" << storeName << "\" не знайдено." << endl;
	}
}
void Remove(Product*& p, int k, int& N)
{
	if (N <= 0 || k < 0 || k >= N) {
		// Перевірка на коректність вхідних параметрів
		return;
	}
	N--;
	Product* t = new Product[N]; // тимчасовий масив

	int j = 0; // індекс в тимчасовому масиві	
	for (int i = 0; i <= N; i++) // скануємо заданий масив
		if (i != k) // і копіюємо елементи,
			t[j++] = p[i]; // які потрібно залишити	
	delete[] p; // знищуємо заданий масив
	p = t; // налаштовуємо вказівник на тимчасовий масив

}
void AddItem(Product*& p, int k, int& N)
{
	N++;
	Product* t = new Product[N]; // Тимчасовий масив

	// Копіюємо елементи до позиції k (включно)
	for (int i = 0; i < k; i++)
	{
		t[i] = p[i];
	}

	// Введення даних для нового товару
	cout << "Введіть дані нового товару: " << endl;
	// Перевірка, чи k не виходить за межі нового масиву
	if (k >= 0 && k <= N)
	{
		editProduct(t[k]);
	}

	// Копіюємо решту елементів після позиції k включно
	for (int i = k + 1; i < N; i++)
	{
		t[i] = p[i - 1];
	}

	delete[] p; // Знищуємо попередній масив
	p = t; // Налаштовуємо вказівник на тимчасовий масив
}
void SaveToFile(Product* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Product)); // записали елементи масиву
	fout.close(); // закрили файл
}
void LoadFromFile(Product*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Product[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Product)); // прочитали елементи масиву
	fin.close(); // закрили файл
}