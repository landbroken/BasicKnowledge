#include "stdafx.h"
using namespace std;

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/
class Solution {
public:
	int method_1(vector<int>& nums)
	{
		if (nums.size() == 1)
		{
			return nums[0];
		}

		sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size() - 1;)
		{
			if (nums[i] == nums[i + 1])
			{
				i += 2;
			}
			else
			{
				//如果出现2次，那i=0和i=1一定一样
				if (i == 0)
				{
					return nums[i];
				}
				//如果不等于下一个也不等于上一个
				else if (nums[i] != nums[i - 1])
				{
					return nums[i];
				}
				else
				{
					i++;
				}
			}
		}
		//前nums.size()-1个都是两个的
		//那么最后一个就是单独的
		return nums[nums.size() - 1];
	}

	int method_2(vector<int>& nums)
	{
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			result = result ^ nums[i];
		}

		return result;
	}

	int singleNumber(vector<int>& nums) {
		return method_2(nums);
	}
};