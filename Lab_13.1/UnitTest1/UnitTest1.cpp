#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_13.1/var.h"
#include "../Lab_13.1/var.cpp"
#include "../Lab_13.1/dod.h" 
#include "../Lab_13.1/dod.cpp" 

using namespace nsVar;
using namespace nsDod;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(DodFunctionTest)
{
public:

    TEST_METHOD(TestDodFunction)
    {
       
        x = 0.5; 
        n = 2;  

        double expectedDod = -0;

        dod();

        Assert::AreEqual(expectedDod, a);
    }
};
