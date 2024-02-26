#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.3/Lab_5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(KFunctionTest)
    {
    public:

        TEST_METHOD(TestKFunction)
        {
            // Перевірка для x >= 1
            double x1 = 2.0;                       
            Assert::AreEqual(k(x1), 7.0734, 0.00001);

            // Перевірка для x < 1
            double x2 = 0.5;          
            Assert::AreEqual(k(x2), 0.99999, 0.00001);
        }

     
    };
}
