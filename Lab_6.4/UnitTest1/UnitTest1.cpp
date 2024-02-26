#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4.it/Lab_6.4.it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int iMax(int* b, const int size);

namespace UnitTestProject
{
    TEST_CLASS(IMaxFunctionTest)
    {
    public:

        TEST_METHOD(TestIMaxFunction)
        {
            // Тест для масиву, де найбільший елемент - 90
            int arr1[] = { 10, 30, 50, 70, 90 };
            int size1 = 5;
            int expected1 = 4; // Індекс найбільшого елемента
            int result1 = iMax(arr1, size1);
            Assert::AreEqual(expected1, result1);

            // Тест для масиву, де найбільший елемент - (-2)
            int arr2[] = { -2, -4, -6, -5, -8 };
            int size2 = 5;
            int expected2 = 0; // Індекс найбільшого елемента
            int result2 = iMax(arr2, size2);
            Assert::AreEqual(expected2, result2);

            // Тест для масиву з одним елементом
            int arr3[] = { 7 };
            int size3 = 1;
            int expected3 = 0; // Індекс єдиного елемента в масиві
            int result3 = iMax(arr3, size3);
            Assert::AreEqual(expected3, result3);
        }
    };
}
