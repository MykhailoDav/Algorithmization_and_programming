#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.1.it/Lab_7.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k);

namespace UnitTestProject
{
    TEST_CLASS(CalcFunctionTest)
    {
    public:

        TEST_METHOD(TestCalcFunction)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** R = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                R[i] = new int[colCount];

            // Заповнимо матрицю з тестовими значеннями
            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    R[i][j] = i * colCount + j;

            int S, k;
            Calc(R, rowCount, colCount, S, k);

            // Очікувані значення для S та k
            int expectedS = 36;
            int expectedk = 9;

            Assert::AreEqual(expectedS, S);
            Assert::AreEqual(expectedk, k);

            for (int i = 0; i < rowCount; i++)
                delete[] R[i];
            delete[] R;
        }
    };
}
