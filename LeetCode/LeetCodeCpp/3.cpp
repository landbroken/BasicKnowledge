#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> t;
		int res = 0, left = 0, right = 0;

		while (right < s.size())
		{
			//如果无重复
			if (t.find(s[right]) == t.end())
			{
				t.insert(s[right]);
				right++;
				res = max(res, (int)t.size());
			}
			//有重复
			else
			{
				t.erase(s[left]);
				left++;
			}
		}
		return res;
	}
};