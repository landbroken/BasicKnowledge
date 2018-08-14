#include "stdafx.h"
using namespace std;

/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/
class Solution {
public:
	bool method_1(vector<int>& nums)
	{
		set<int> s;
		for (auto &it : nums)
		{
			if (s.find(it) == s.end())
			{
				s.insert(it);
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool method_2(vector<int>& nums)
	{
		if (nums.size() <= 1)
		{
			return false;
		}

		sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size() - 1;i++)
		{
			if (nums[i] == nums[i + 1])
			{
				return true;
			}
		}
		return false;
	}

	bool containsDuplicate(vector<int>& nums) {
		return method_2(nums);
	}
};