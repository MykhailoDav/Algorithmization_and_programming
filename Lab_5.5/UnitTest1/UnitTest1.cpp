#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.5/Lab_5.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestToBinary)
		{
			int depth = 0;
			// Перевірка правильності перетворення числа 10 в двійкову систему
			std::string binaryResult = toBinary(10,1, depth);
			Assert::AreEqual(binaryResult.c_str(), "1010");

			// Перевірка правильності перетворення числа 0 в двійкову систему
			binaryResult = toBinary(0,1, depth);
			Assert::AreEqual(binaryResult.c_str(), "0");

		}
	};
}
