#include "stdafx.h"
#include "LeetCodeCppTest.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
*/

/*
s思路：
1. 看了提示，用binary search tree。用BST，在c++就是用set或map了，
因为这两样就是用bst实现的。

2. 因为没有重复，所以不能用hash。坐标之差在一个范围内，我们可以
每次只在这个范围内寻找数，比如：从左往右移动，当长度大于k，那么
就把搜索区间的最左边删除，类似与two pointer的方法，只是这个窗口
达到k后就不增加了；

3. 数据之差如何搞定呢？当然可以在窗口内双重循环找到所有数据之差
然后判断是否存在一个数据差小于t，但这样复杂度就是o(k^2),由于没窗
口每次移动一下，都要这样来一遍，所以总的复杂度o(nk^2)，还是太大。

4. 主要的问题是：在k长的窗口内，是否存在|nums[i]-nums[j]|<=t的一对
数据？由于数据是无序的，难道一定要遍历所有o(k^2)的可能吗？这几天都
在说，要从无序中看出是否有序的可能，先不说马上能看到，但一定要有
信念，不然真看不到，因为心里着急，气急败坏，没有信心嘛。

5. 先把上面的不等式展开：-t<=nums[i]-nums[j]<=t,继续处理：

nums[i]-t<=nums[j]<=nums[i]+t

注意看，这就和原来不一样了，我们假设i是从左往右遍历的当前的数的index
*/
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k<1 || t<0) return false;

		set<long> ss;//bug:调试很久，刚开始用int,发现要做运算，极限case过不了，所以用long保护
		long lt = t;

		for (int i = 0;i<nums.size();i++)
		{
			//滑动窗口大于k，移除最左边
			if (i>k)
				ss.erase(nums[i - k - 1]);
			//取nums[i]-t<=nums[j]
			//bug:只需要把其中之一转换成long即可
			set<long>::iterator it = ss.lower_bound(nums[i] - lt);
			//判断是否有nums[i]-t<=nums[j]<=nums[i]+t
			//*it即nums[j]
			if (it != ss.end() && (*it) - nums[i] <= t)
				return true;
			//没有则将nums[j]加入窗口中
			ss.insert(nums[i]);
		}
		return false;
	}
};

bool test_220(vector<int> vec,int k,int t)
{
	Solution s;
	auto ret = s.containsNearbyAlmostDuplicate(vec, k, t);//true
	return ret;
}