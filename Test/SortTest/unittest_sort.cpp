#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../排序/sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestSort)
	{
	private:
		const static int bufferSize = 10;
		const int right[bufferSize] = { 0,1,2,3,4,5,6,7,8,9 };
		int test1[bufferSize] = { 1,5,8,3,9,2,0,4,7,6 };
		int test2[bufferSize] = { 1,2,3,4,5,6,7,8,9,0 };
		int test3[bufferSize] = { 2,3,1,4,5,6,7,8,9,0 };
		int test4[bufferSize] = { 6,1,5,4,2,9,3,0,7,8 };
		int test5[bufferSize] = { 8,2,1,7,6,5,0,4,3,9 };

	public:
		
		TEST_METHOD(TestBubbleSort)
		{
			// TODO: 在此输入测试代码
			BubbleSort(test1, bufferSize);
			BubbleSort(test2, bufferSize);
			BubbleSort(test3, bufferSize);
			BubbleSort(test4, bufferSize);
			BubbleSort(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestCocktailSort)
		{
			// TODO: 在此输入测试代码
			CocktailSort(test1, bufferSize);
			CocktailSort(test2, bufferSize);
			CocktailSort(test3, bufferSize);
			CocktailSort(test4, bufferSize);
			CocktailSort(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestSelectSort)
		{
			SelectSort(test1, bufferSize);
			SelectSort(test2, bufferSize);
			SelectSort(test3, bufferSize);
			SelectSort(test4, bufferSize);
			SelectSort(test5, bufferSize);

			// TODO: 在此输入测试代码
			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestInsertionSort)
		{
			// TODO: 在此输入测试代码
			InsertionSort(test1, bufferSize);
			InsertionSort(test2, bufferSize);
			InsertionSort(test3, bufferSize);
			InsertionSort(test4, bufferSize);
			InsertionSort(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestInsertionSortDichotomy)
		{
			// TODO: 在此输入测试代码
			InsertionSortDichotomy(test1, bufferSize);
			InsertionSortDichotomy(test2, bufferSize);
			InsertionSortDichotomy(test3, bufferSize);
			InsertionSortDichotomy(test4, bufferSize);
			InsertionSortDichotomy(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestShellSort)
		{
			// TODO: 在此输入测试代码
			ShellSort(test1, bufferSize);
			ShellSort(test2, bufferSize);
			ShellSort(test3, bufferSize);
			ShellSort(test4, bufferSize);
			ShellSort(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestMergeSort)
		{
			// TODO: 在此输入测试代码
			MergeSort(test1, 0, bufferSize - 1);
			MergeSort(test2, 0, bufferSize - 1);
			MergeSort(test3, 0, bufferSize - 1);
			MergeSort(test4, 0, bufferSize - 1);
			MergeSort(test5, 0, bufferSize - 1);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}

		TEST_METHOD(TestQuickSort)
		{
			// TODO: 在此输入测试代码
			QuickSort(test1, 0, bufferSize - 1);
			QuickSort(test2, 0, bufferSize - 1);
			QuickSort(test3, 0, bufferSize - 1);
			QuickSort(test4, 0, bufferSize - 1);
			QuickSort(test5, 0, bufferSize - 1);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}
		
		TEST_METHOD(TestHeapSort)
		{
			// TODO: 在此输入测试代码
			HeapSort(test1, bufferSize);
			HeapSort(test2, bufferSize);
			HeapSort(test3, bufferSize);
			HeapSort(test4, bufferSize);
			HeapSort(test5, bufferSize);

			Assert::AreEqual(true, IsEqual(test1, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test2, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test3, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test4, right, bufferSize));
			Assert::AreEqual(true, IsEqual(test5, right, bufferSize));
		}
	};
}