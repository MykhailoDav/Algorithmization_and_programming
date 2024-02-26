#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Lab_10.1/Lab_10.1.cpp"
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
