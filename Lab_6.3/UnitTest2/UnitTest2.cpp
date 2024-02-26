#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.3.rec/Lab_6.3.rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestProject
{
    TEST_CLASS(MinFunctionTest)
    {
    public:

        TEST_METHOD(TestMinFunction)
        {
            // Тест для масиву, в якому найменший непарний елемент - 3
            int arr1[] = { 2, 4, 6, 8, 3, 7, 9 };
            int size1 = 7;
            int expected1 = 3;
            int result1 = Min(arr1, size1,3,3 );
            Assert::AreEqual(expected1, result1);

            // Тест для масиву, в якому немає непарних елементів
            int arr2[] = { 2, 4, 6, 8 };
            int size2 = 4;
            int expected2 = 0; // Оскільки немає непарних елементів, функція повинна повернути 0
            int result2 = Min(arr2, size2,0,0);
            Assert::AreEqual(expected2, result2);

            // Тест для масиву з одним елементом
            int arr3[] = { 7 };
            int size3 = 1;
            int expected3 = 7;
            int result3 = Min(arr3, size3,7,6);
            Assert::AreEqual(expected3, result3);
        }
    };
}
