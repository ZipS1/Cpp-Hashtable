#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(Class)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(2, 2);
		}
	};

	TEST_CLASS(Class2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(2, 2);
		}
	};
}
