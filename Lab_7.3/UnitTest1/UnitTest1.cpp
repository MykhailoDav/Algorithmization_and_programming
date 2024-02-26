#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.it/Lab_7.3.it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(SumOfRowsWithNegativeFunctionTest)
    {
    public:

        TEST_METHOD(TestSumOfRowsWithNegativeFunction)
        {
            const int n = 4;
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++) {
                testMatrix[i] = new int[n];
            }

           
            testMatrix[0][0] = 1;
            testMatrix[0][1] = -2;
            testMatrix[0][2] = 3;
            testMatrix[0][3] = -4;
            testMatrix[1][0] = 5;
            testMatrix[1][1] = 6;
            testMatrix[1][2] = -7;
            testMatrix[1][3] = 8;
            testMatrix[2][0] = 9;
            testMatrix[2][1] = -10;
            testMatrix[2][2] = 11;
            testMatrix[2][3] = -12;
            testMatrix[3][0] = 13;
            testMatrix[3][1] = 14;
            testMatrix[3][2] = 15;
            testMatrix[3][3] = 16;

            int ifNegative = 0;

            // Виклик функції sumOfRowsWithNegative
            int sum = sumOfRowsWithNegative(testMatrix, n, ifNegative);

            // Очікуваний результат після виклику функції sumOfRowsWithNegative
            int expectedSum = 8;  // Сума від'ємних елементів у рядках, які мають від'ємні елементи

            Assert::AreEqual(expectedSum, sum);
            Assert::AreEqual(3, ifNegative); // Очікувана кількість рядків з від'ємними елементами.

            for (int i = 0; i < n; i++) {
                delete[] testMatrix[i];
            }
            delete[] testMatrix;
        }
    };
}
