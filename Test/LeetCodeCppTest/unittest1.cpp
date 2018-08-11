#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../LeetCode/LeetCodeCpp/LeetCodeCppTest.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LeetCodeCppTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test_1)
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

		TEST_METHOD(Test_44)
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