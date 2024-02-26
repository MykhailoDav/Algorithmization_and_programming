#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.4/Lab_5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 5;
			int k = 1;
			double rez = S1(N, k);
			Assert::AreEqual(0.192129, rez, 0.00001);
		}
	};
}
