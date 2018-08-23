#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../LeetCode/LeetCodeCpp/LeetCodeCppTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeCppTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Leet_1)
		{
			// TODO: 在此输入测试代码
			vector<int> nums = { 3, 2, 4};
			auto ret = test_1(nums,6);
			Assert::AreEqual(1, ret[0]);
			Assert::AreEqual(2, ret[1]);
			vector<int> nums2 = { 2, 7, 11, 15 };
			ret = test_1(nums2, 9);
			Assert::AreEqual(0, ret[0]);
			Assert::AreEqual(1, ret[1]);
		}

		TEST_METHOD(Leet_44)
		{
			// TODO: 在此输入测试代码
			string s, p;
			bool ret = false;
			s = "abefcdgiescdfimde";
			p = "ab*cd?i*de";
			ret = test_44(s, p);
			Assert::AreEqual(true, ret);
			s = "aa";
			p = "a";
			ret = test_44(s, p);
			Assert::AreEqual(false, ret);

			s = "aa";
			p = "*";
			ret = test_44(s, p);
			Assert::AreEqual(true, ret);

			s = "cb";
			p = "?a";
			ret = test_44(s, p);
			Assert::AreEqual(false, ret);

			s = "adceb";
			p = "*a*b";
			ret = test_44(s, p);
			Assert::AreEqual(true, ret);

			s = "acdcb";
			p = "a*c?b";
			ret = test_44(s, p);
			Assert::AreEqual(false, ret);

			s = "adceb";
			p = "a?c*";
			ret = test_44(s, p);
			Assert::AreEqual(true, ret);

			s = "ktuttwwgcbixa";
			p = "?t?ttwwgcbixa";
			ret = test_44(s, p);
			Assert::AreEqual(true, ret);
		}

		TEST_METHOD(Leet_122)
		{
			// TODO: 在此输入测试代码
			int ret = test_122();
			Assert::AreEqual(2, ret);
		}

		TEST_METHOD(Leet_220)
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

		TEST_METHOD(Leet_234)
		{
			// TODO: 在此输入测试代码
			bool ret = false;
			int arr[2] = { 1,2 };

			ret = test_234(arr, 2);//false
			Assert::AreEqual(false, ret);

			int arr2[4] = { 1,2,2,1 };
			ret = test_234(arr2, 4);//true
			Assert::AreEqual(true, ret);
		}

		TEST_METHOD(Leet_278)
		{
			// TODO: 在此输入测试代码
			int ret = test_278(0x7FFFFFFF);
			Assert::AreEqual(1792997410, ret);
		}

		TEST_METHOD(Leet_387)
		{
			// TODO: 在此输入测试代码
			string str;
			int ret;
			str = "leetcode";
			ret = test_387(str);
			Assert::AreEqual(0, ret);

			str = "loveleetcode";
			ret = test_387(str);
			Assert::AreEqual(2, ret);
		}

	};
}