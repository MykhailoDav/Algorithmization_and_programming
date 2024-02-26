#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4.rec/Lab_6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int iMaxRecursive(int* b, const int size, int i, int max, int imax);

namespace UnitTestProject
{
    TEST_CLASS(IMaxRecursiveFunctionTest)
    {
    public:

        TEST_METHOD(TestIMaxRecursiveFunction)
        {
            // Тест для масиву, де найбільший елемент - 90
            int arr1[] = { 10, 30, 50, 70, 90 };
            int size1 = 5;
            int expected1 = 4; // Індекс найбільшого елемента
            int result1 = iMaxRecursive(arr1, size1, 0, arr1[0], 0);
            Assert::AreEqual(expected1, result1);

            // Тест для масиву, де найбільший елемент - (-2)
            int arr2[] = { -2, -4, -6, -5, -8 };
            int size2 = 5;
            int expected2 = 0; // Індекс найбільшого елемента
            int result2 = iMaxRecursive(arr2, size2, 0, arr2[0], 0);
            Assert::AreEqual(expected2, result2);

            // Тест для масиву з одним елементом
            int arr3[] = { 7 };
            int size3 = 1;
            int expected3 = 0; // Індекс єдиного елемента в масиві
            int result3 = iMaxRecursive(arr3, size3, 0, arr3[0], 0);
            Assert::AreEqual(expected3, result3);
        }
    };
}
