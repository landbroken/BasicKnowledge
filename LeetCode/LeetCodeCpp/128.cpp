#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//内部是哈希实现，O(1)，添加是O(n)
		unordered_set<int> uset;
		for (int num : nums)
			uset.insert(num);

		//遍历是O(n)
		int longest = 0;
		for (int num : uset)
		{
			//如果已经是一个子序列的最小值了
			if (uset.find(num - 1) == uset.end())
			{
				int cnt = 1;
				//循环找到连续递增的次数
				while (uset.find(num + 1) != uset.end())
				{
					num++;
					cnt++;
				}
				longest = max(longest, cnt);
			}
		}
		return longest;
	}
};