#include "stdafx.h"
#include "CppUnitTest.h"
#include"../STL/stl_demo.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace STLTest
{		
	TEST_CLASS(UnitTestSTL)
	{
	private:
		const int arrSize = 10;
		int arr[10] = { 0,9,8,7,6,5,4,3,2,1 };
		int arr2[20] = { 3,5,7,9,11,13,15,17,19,1,0,9,8,7,6,5,4,3,2,1 };
		int arrSort[20] = { 0,1,1,2,3,3,4,5,5,6,7,7,8,9,9,11,13,15,17,19 };
	public:
		
		TEST_METHOD(TestSet)
		{
			//添加
			std::set<int> out;
			for (size_t i = 0; i < arrSize; i++)
			{
				out.insert(arr[i]);
			}
			SetDemo demo;
			demo.Insert(arr, arrSize);
			Assert::AreEqual(true, demo.IsEqual(out));
			//忽略相同添加
			int tmp[1] = {5};
			demo.Insert(tmp, 1);
			Assert::AreEqual(true, demo.IsEqual(out));
			Assert::AreEqual(arrSize, (int)out.size());
			out.insert(5);
			Assert::AreEqual(arrSize, (int)out.size());
			//查找
			Assert::AreEqual(true, demo.Find(5));
			Assert::AreEqual(false, demo.Find(50));
			Assert::AreEqual(1, demo.Count(3));
			Assert::AreEqual(0, demo.Count(30));
			//删除
			demo.ElementDelete(5);
			Assert::AreEqual(false, demo.Find(5));
			Assert::AreEqual(0, demo.Count(5));
			Assert::AreEqual(false, demo.IsEqual(out));
			out.erase(5);
			Assert::AreEqual(true, demo.IsEqual(out));
			//清空
			demo.Clear();
			auto innerSet = demo.GetInnerSet();
			int size = innerSet.size();
			Assert::AreEqual(0, size);

		}

		TEST_METHOD(TestList)
		{
			//添加
			ListDemo demo;
			demo.Insert(arr, arrSize);
			int insertSize = sizeof(arr2)/sizeof(int);
			Assert::AreEqual(true, demo.IsEqual(arr2, insertSize));
			demo.Sort();
			Assert::AreEqual(true, demo.IsEqual(arrSort, insertSize));
			//清空
			demo.Clear();
			auto innerVector = demo.GetOutput();
			int size = innerVector.size();
			Assert::AreEqual(0, size);
		}
	};
}