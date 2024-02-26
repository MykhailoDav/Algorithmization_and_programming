#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Lab_8.1.string/Lab_8.1.string.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(StringCountFunctionTest)
{
public:

    TEST_METHOD(TestCountFunction)
    {
  
        const string testString = "while do something while do something else while";

        int result = Count(testString);

        int expectedCount = 3;

        Assert::AreEqual(expectedCount, result);
    }
};
