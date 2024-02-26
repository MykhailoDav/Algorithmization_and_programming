#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.2.rec/Lab_6.2.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



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
            int result1 = Max(arr1, size1, 1, arr1[0]);
            int expected1 = 10;
            Assert::AreEqual(expected1, result1);

            // Тест для масиву, в якому найбільший елемент - (-2)
            int arr2[] = { -2, -4, -6, -5, -8 };
            int size2 = 5;
            int result2 = Max(arr2, size2, 1, arr2[0]);
            int expected2 = -2;
            Assert::AreEqual(expected2, result2);

            // Тест для масиву з одним елементом
            int arr3[] = { 7 };
            int size3 = 1;
            int result3 = Max(arr3, size3, 1, arr3[0]);
            int expected3 = 7;
            Assert::AreEqual(expected3, result3 );
        }
    };
}
