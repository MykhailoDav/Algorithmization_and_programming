#include "pch.h" 
#include "CppUnitTest.h"
#include <cstring>
#include "../Lab_8.1.it/Lab_8.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectName
{
    TEST_CLASS(CountFunctionTest)
    {
    public:

        TEST_METHOD(TestCountFunction)
        {
            char emptyStr[] = "";
            Assert::AreEqual(0, Count(emptyStr));

            char noWhileStr[] = "Hello world!";
            Assert::AreEqual(0, Count(noWhileStr));

            char oneWhileStr[] = "Hello while world!";
            Assert::AreEqual(1, Count(oneWhileStr));

            char multipleWhileStr[] = "while Hello while while world!";
            Assert::AreEqual(3, Count(multipleWhileStr));
        }
    };
}
