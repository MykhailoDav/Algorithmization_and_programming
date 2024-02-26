#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.rec/Lab_7.3.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestProject
{
    TEST_CLASS(SumOfRowFunctionTest)
    {
    public:

        TEST_METHOD(TestSumOfRowFunction)
        {
            const int n = 5;
            int testRow[n];

            // Заповніть тестовий ряд значеннями, що підходять для вашого тесту.
            // Ось приклад з деякими від'ємними елементами:
            testRow[0] = 1;
            testRow[1] = -2;
            testRow[2] = 3;
            testRow[3] = -4;
            testRow[4] = 5;

            int ifNegative = 0;

            // Виклик функції sumOfRow
            int sum = sumOfRow(testRow, n, ifNegative);

            // Очікуваний результат після виклику функції sumOfRow
            int expectedSum = -6; // Сума від'ємних елементів у рядку

            Assert::AreEqual(expectedSum, sum);
            Assert::AreEqual(2, ifNegative); // Очікувана кількість від'ємних елементів у рядку.
        }
    };
}
