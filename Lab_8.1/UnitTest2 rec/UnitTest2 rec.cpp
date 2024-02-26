#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1.rec/Lab_8.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int Count(char* str, int i);

namespace UnitTestProject
{
    TEST_CLASS(CountFunctionTest)
    {
    public:

        TEST_METHOD(TestCountFunction)
        {
            char testString1[] = "while do something while condition";
            int result1 = Count(testString1, 0);
            Assert::AreEqual(2, result1);

            char testString2[] = "while do while something while condition";
            int result2 = Count(testString2, 0);
            Assert::AreEqual(3, result2);

            char testString3[] = "if condition then do something";
            int result3 = Count(testString3, 0);
            Assert::AreEqual(0, result3);
        }
    };
}
