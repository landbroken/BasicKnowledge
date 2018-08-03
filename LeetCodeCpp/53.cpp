#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0)
			return 0;
		int sum = 0;
		int maxsum = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
			if (sum > maxsum)
				maxsum = sum;
			if (sum < 0)
				sum = 0;
		}
		return maxsum;
	}
};