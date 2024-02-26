#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1.rec/Lab_7.1.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);

namespace UnitTestProject
{
	TEST_CLASS(SortAndCalcFunctionTest)
	{
	public:

		TEST_METHOD(TestSortFunction)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** R = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				R[i] = new int[colCount];
			}

			// Заповніть матрицю з тестовими значеннями для сортування
			int testValues[3][3] = {
				{9, 8, 7},
				{6, 5, 4},
				{3, 2, 1}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					R[i][j] = testValues[i][j];
				}
			}

			Sort(R, rowCount, colCount, 0, 0);

			// Очікуваний результат після сортування
			int expectedValues[3][3] = {
				{3, 2, 1},
				{6, 5, 4},
				{9, 8, 7}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::AreEqual(expectedValues[i][j], R[i][j]);
				}
			}

			for (int i = 0; i < rowCount; i++)
				delete[] R[i];
			delete[] R;
		}

		TEST_METHOD(TestCalcFunction)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** R = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				R[i] = new int[colCount];
			}

			// Заповніть матрицю з тестовими значеннями для функції Calc
			int testValues[3][3] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					R[i][j] = testValues[i][j];
				}
			}

			int S = 0, k = 0;
			Calc(R, rowCount, colCount, S, k, 0, 0);

			// Очікувані значення для S і k після виклику функції Calc
			int expectedS = 44;
			int expectedk = 8;

			Assert::AreEqual(expectedS, S);
			Assert::AreEqual(expectedk, k);

			for (int i = 0; i < rowCount; i++)
				delete[] R[i];
			delete[] R;
		}
	};
}
