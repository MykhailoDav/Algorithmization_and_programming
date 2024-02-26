#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_13.2.1/Lab_13.2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab132UnitTest
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMAX)
        {
            // Arrange
            int a = 5;
            int b = 10;

            // Act
            int result = MAX(a, b);

            // Assert
            Assert::AreEqual(b, result);  // Очікуємо, що максимальне значення буде b
        }
    };
}
