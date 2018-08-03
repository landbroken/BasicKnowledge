#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../Search/search.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchTest
{		
	TEST_CLASS(UnitTestSearch)
	{
	private:
		const int static arrSize = 10;
		int a[arrSize] = { 1,2,3,4,5,10,11,12,13,14 };
	public:
		
		TEST_METHOD(TestSequenceSearch)
		{
			int ret = 0;
			ret = SequenceSearch(a, 10, arrSize);
			Assert::AreEqual(5, ret);
			ret = SequenceSearch(a, 6, arrSize);
			Assert::AreEqual(-1, ret);
		}

		TEST_METHOD(TestBinarySearch)
		{
			int ret = 0;
			ret = BinarySearch(a, 10, arrSize);
			Assert::AreEqual(5, ret);
			ret = BinarySearch_Recursion(a, 11, 0, arrSize - 1);
			Assert::AreEqual(6, ret);
			ret = BinarySearch(a, 6, arrSize);
			Assert::AreEqual(-1, ret);
			ret = BinarySearch_Recursion(a, 6, 0, arrSize - 1);
			Assert::AreEqual(-1, ret);
		}

		TEST_METHOD(TestInsertionSearch)
		{
			int ret = 0;
			ret = InsertionSearch(a, 10, 0, arrSize - 1);
			Assert::AreEqual(5, ret);
			ret = InsertionSearch_Recursion(a, 11, 0, arrSize - 1);
			Assert::AreEqual(6, ret);
			ret = InsertionSearch(a, 6, 0, arrSize - 1);
			Assert::AreEqual(-1, ret);
			ret = InsertionSearch_Recursion(a, 6, 0, arrSize - 1);
			Assert::AreEqual(-1, ret);
		}
	};
}