#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba_5.0/Laba_5.0.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = F(1, 1 ,1);
			Assert::AreEqual(t, 0.236024, 0.00001);
		}

	};
}
