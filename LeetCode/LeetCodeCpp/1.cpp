#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
class Solution {
public:
	/*
	暴力搜索，需要O(n^2)的时间，O(1)的额外空间
	*/
	vector<int> method_1(vector<int>& nums, int target)
	{
		vector<int> ret;
		for (int i = 0;i<nums.size();i++)
		{
			for (int j = i + 1;j<nums.size();j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
	}

	/*
	利用哈希，需要O(n)的时间和O(n)的空间
	参考：
	https://www.cnblogs.com/eudiwffe/p/6282635.html
	*/
	vector<int> method_2(vector<int>& nums, int target)
	{
		vector<int> v(2, 0);
		// val+id
		unordered_map<int, int> hash;
		// we can search num and insert it to hash map at same time
		// and current num must be not in hash map
		for (int i = nums.size(); i--; hash[nums[i]] = i)
		{
			if (hash.find(target - nums[i]) == hash.end())
				continue;

			v[0] = i;           // the index from 0 to n-1
			v[1] = hash[target - nums[i]];
			return v;
		}

		return v;                   // no answer return {0,0}
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		return method_2(nums, target);
	}
};

vector<int> test_1(vector<int>& nums, int target)
{
	Solution s;
	return s.twoSum(nums, target);
}