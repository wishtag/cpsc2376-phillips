#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../../practice/practice03/practice03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestSumRange1)
		{
			Assert::AreEqual(15, MathUtils::sumRange(1,5));
		}
		TEST_METHOD(TestSumRange2)
		{
			Assert::AreEqual(14, MathUtils::sumRange(-1, 5));
		}
		TEST_METHOD(TestSumRange3)
		{
			Assert::AreEqual(5, MathUtils::sumRange(5, 5));
		}

		TEST_METHOD(TestContainsNegative1)
		{
			std::vector<int> test1 = { 1,2,3 };
			Assert::IsFalse(MathUtils::containsNegative(test1));
		}
		TEST_METHOD(TestContainsNegative2)
		{
			std::vector<int> test2 = { 1,-2,3 };
			Assert::IsTrue(MathUtils::containsNegative(test2));
		}
		TEST_METHOD(TestContainsNegative3)
		{
			std::vector<int> test3 = {};
			Assert::IsFalse(MathUtils::containsNegative(test3));
		}

		TEST_METHOD(TestFindMax1)
		{
			std::vector<int> test1 = { 8,1,12,6 };
			Assert::AreEqual(12, MathUtils::findMax(test1));
		}
		TEST_METHOD(TestFindMax2)
		{
			std::vector<int> test2;
			Assert::ExpectException<std::invalid_argument>([&](){MathUtils::findMax(test2);});
		}
		TEST_METHOD(TestFindMax3)
		{
			std::vector<int> test3 = { 8,8,8,8 };
			Assert::AreEqual(8, MathUtils::findMax(test3));
		}
	};
}
