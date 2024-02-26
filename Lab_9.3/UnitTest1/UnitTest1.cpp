#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.3/Lab_9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace
{
	TEST_CLASS(ProductTest)
	{
	public:

		TEST_METHOD(TestSortProductsByName)
		{
			const int N = 3;  // Adjust the size as needed
			Product* p = new Product[N];

			// Initialize your products, for example:
			p[0] = { "Product3", "StoreC", 25.0, 3.0, "kg" };
			p[1] = { "Product1", "StoreA", 15.0, 2.5, "pcs" };
			p[2] = { "Product2", "StoreB", 20.0, 1.5, "l" };

			// Call the function you want to test
			sortProductsByName(p, N);

			// Assert statements to check if the sorting is correct
			Assert::AreEqual(p[0].name, std::string("Product1"));
			Assert::AreEqual(p[1].name, std::string("Product2"));
			Assert::AreEqual(p[2].name, std::string("Product3"));

			delete[] p;
		}
	};
}
