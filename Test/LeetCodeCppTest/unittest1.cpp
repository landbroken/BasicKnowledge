#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../LeetCode/LeetCodeCpp/LeetCodeCppTest.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeCppTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_122)
		{
			// TODO: 在此输入测试代码
			int ret = test_122();
			Assert::AreEqual(2, ret);
		}

		TEST_METHOD(Test_220)
		{
			// TODO: 在此输入测试代码
			bool ret = false;

			std::vector<int> vec1 = { 1, 2, 3, 1 };
			ret = test_220(vec1, 3, 0);//true
			Assert::AreEqual(true, ret);

			std::vector<int> vec2 = { 1, 0, 1, 1 };
			ret = test_220(vec2, 1, 2);//true
			Assert::AreEqual(true, ret);

			std::vector<int> vec3 = { 1, 5, 9, 1, 5, 9, 1, 5, 9 };
			ret = test_220(vec3, 2, 3);//false
			Assert::AreEqual(false, ret);
		}

		TEST_METHOD(Test_278)
		{
			// TODO: 在此输入测试代码
			int ret = test_278(0x7FFFFFFF);
			Assert::AreEqual(1792997410, ret);
		}
	};
}