#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2.it/Lab_6.2.it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int Max(int* a, const int size);

namespace UnitTestProject
{
    TEST_CLASS(MaxFunctionTest)
    {
    public:

        TEST_METHOD(TestMaxFunction)
        {
            // Тест для масиву, в якому найбільший елемент - 10
            int arr1[] = { 2, 4, 6, 8, 10 };
            int size1 = 5;
            int result1 = Max(arr1, size1);
            int expected1 = 10;
            Assert::AreEqual(result1, expected1);

            // Тест для масиву, в якому найбільший елемент - (-5)
            int arr2[] = { -2, -4, -6, -5, -8 };
            int size2 = 5;
            int result2 = Max(arr2, size2);
            int expected2 = -2;
            Assert::AreEqual(result2, expected2);

            // Тест для масиву з одним елементом
            int arr3[] = { 7 };
            int size3 = 1;
            int result3 = Max(arr3, size3);
            int expected3 = 7;
            Assert::AreEqual(result3, expected3);
        }
    };
}
