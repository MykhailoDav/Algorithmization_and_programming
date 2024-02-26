#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.1/Lab_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace
{
	TEST_CLASS(IsValidExpValueTest)
	{
	public:

		TEST_METHOD(TestValidExpValue)
		{
			Assert::IsTrue(isValidExpValue(5.0));

			Assert::IsTrue(isValidExpValue(0.0));
		}

		TEST_METHOD(TestInvalidExpValue)
		{
			Assert::IsFalse(isValidExpValue(-3.0));

		}
	};
}
