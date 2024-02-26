#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.2/Lab_5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest2
{
    TEST_CLASS(AFunctionTest)
    {
    public:

        TEST_METHOD(TestAFunction)
        {
            double x = 1.0;
            int n = 2;
            double a = -0.5;

            A(x, n, a);
     

            // Перевірка, чи функція A правильно обчислила a для заданих значень x і n
            Assert::AreEqual(a, 0.3);
        }

        // Додайте інші тести за потреби
    };
}
