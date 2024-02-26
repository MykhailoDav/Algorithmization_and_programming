#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2.rec/Lab_7.2.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestProject
{
    TEST_CLASS(FindMinInRowFunctionTest)
    {
    public:

        TEST_METHOD(TestFindMinInRowFunction)
        {
            const int n = 4;
            int testRow[4] = { 5, 3, 9, 2 };

            int min = FindMinInRow(testRow, 0, n, testRow[0]);

            // Очікуваний результат після виклику функції FindMinInRow
            int expectedValue = 2;  // Мінімальний елемент в масиві

            Assert::AreEqual(expectedValue, min);
        }
    };
}
