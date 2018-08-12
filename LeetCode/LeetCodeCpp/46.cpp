#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
class Solution {
public:
	void permuteDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
		//全部都visited了
		if (level == num.size())
		{
			res.push_back(out);
		}
		else
		{
			for (int i = 0; i < num.size(); ++i)
			{
				if (visited[i] == 0)
				{
					visited[i] = 1;
					out.push_back(num[i]);

					permuteDFS(num, level + 1, visited, out, res);

					out.pop_back();
					visited[i] = 0;
				}
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> out;
		vector<int> visited(nums.size(), 0);

		permuteDFS(nums, 0, visited, out, res);

		return res;
	}
};