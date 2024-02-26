#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1.char/Lab_8.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int Count(char* s);

namespace UnitTestProject
{
    TEST_CLASS(CountFunctionTest)
    {
    public:

        TEST_METHOD(TestCountFunction)
        {
            // Arrange
            char testString1[] = "while loop while while condition";
            char testString2[] = "for loop, no 'while' here";

            // Act
            int count1 = Count(testString1);
            int count2 = Count(testString2);

            // Assert
            Assert::AreEqual(3, count1); 
            Assert::AreEqual(1, count2);
        }
    };
}
