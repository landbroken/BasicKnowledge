#include "stdafx.h"

/*
打乱一个没有重复元素的数组。

示例:

// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
*/
class Solution {
private:
	vector<int> _vec;
public:
	Solution(vector<int> nums) {
		_vec.clear();
		_vec.assign(nums.begin(), nums.end());
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return _vec;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res = _vec;
		for (int i = 0; i < res.size(); ++i)
		{
			//参考
			//https://yjk94.wordpress.com/2017/03/17/%E6%B4%97%E7%89%8C%E7%9A%84%E6%AD%A3%E7%A1%AE%E5%A7%BF%E5%8A%BF-knuth-shuffle%E7%AE%97%E6%B3%95/
			//注意洗牌用Knuth shuffle算法
			int t = i + rand() % (res.size() - i);
			swap(res[i], res[t]);
		}
		return res;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/
