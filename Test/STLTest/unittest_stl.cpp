#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../STL/stl_demo.h"
#include <string>
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
		int arr3[10] = { 2,5,3,9,7,0,6,1,4,8 };
	public:
		TEST_METHOD(TestVector)
		{
			//初始化，插入，修改
			const int arrvec[4] = { 3,2,2,2 };
			int arrvec2[4];
			std::vector<int> vec(3, 1);//1,1,1
			vec.insert(vec.begin(), 2);//2,1,1,1
			std::vector<int>::iterator it = vec.begin();
			for (size_t i = 0; i < sizeof(arrvec2) / sizeof(int); i++)
			{
				(*it)++;
				arrvec2[i] = *it;
				it++;
				Assert::AreEqual(arrvec[i], arrvec2[i]);
			}
			auto _it = vec.rbegin();
		}

		TEST_METHOD(TestSet)
		{
			//添加
			//无序数组添加，set内部自动排序
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

		TEST_METHOD(TestMap)
		{
			//添加
			MapDemo m;
			m.Insert(1, "student_one");
			m.Insert(2, "student_two");
			m.Insert(3, "student_three");
			m.Output();

			//查询返回迭代器
			//正确的查询，迭代器指向该值
			std::string tmp = "";
			auto mapStudent = m.GetMap();
			auto ret = mapStudent.find(1);
			tmp = "student_one";
			Assert::AreEqual(1, ret->first);
			Assert::AreEqual(tmp, ret->second);
			ret = mapStudent.find(2);
			tmp = "student_two";
			Assert::AreEqual(2, ret->first);
			Assert::AreEqual(tmp, ret->second);

			//失败的查询，迭代器指向end
			auto fail= mapStudent.find(0);
			bool isEnd = fail == mapStudent.end();
			Assert::AreEqual(true, isEnd);
		}
	};
}