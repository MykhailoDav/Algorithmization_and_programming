#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1.rec/Lab_6.1.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int Sum(int* b, const int size);

namespace UnitTestProject
{
    TEST_CLASS(SumFunctionTest)
    {
    public:

        TEST_METHOD(TestSumFunction)
        {
            int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            int size1 = 10;
            int result1 = Sum(arr1, size1, 0, 0);
            int expected1 = 43;
            Assert::AreEqual(expected1, result1);

            int arr2[] = { 12, 15, 18, 21, 24 };
            int size2 = 5;
            int result2 = Sum(arr2, size2, 0, 0);
            int expected2 = 54; // Всі елементи задовольняють умову (подільні на 3)
            Assert::AreEqual(expected2, result2);

            int arr3[] = { 11, 13, 17, 19, 23 };
            int size3 = 5;
            int result3 = Sum(arr3, size3, 0, 0);
            int expected3 = 83; // Всі елементи не задовольняють умову (не подільні на 2 та 3)
            Assert::AreEqual(expected3, result3);
        }
    };
}
