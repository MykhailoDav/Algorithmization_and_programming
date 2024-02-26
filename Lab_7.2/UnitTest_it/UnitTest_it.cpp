#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2.it/Lab_7.2.it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestProject
{
    TEST_CLASS(FindMaxFromMinsFunctionTest)
    {
    public:

        TEST_METHOD(TestFindMaxFromMinsFunction)
        {
            const int k = 3;
            const int n = 3;
            int** a = new int* [k];
            for (int i = 0; i < k; i++) {
                a[i] = new int[n];
            }

            // Заповніть матрицю з тестовими значеннями
            int testValues[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = testValues[i][j];
                }
            }

            int maxValueFromMinElement;
            FindMaxFromMins(a, k, n, maxValueFromMinElement);

            // Очікуваний результат після виклику функції FindMaxFromMins
            int expectedValue = 7;  // Мінімальний елемент в першому рядку

            Assert::AreEqual(expectedValue, maxValueFromMinElement);

            for (int i = 0; i < k; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
