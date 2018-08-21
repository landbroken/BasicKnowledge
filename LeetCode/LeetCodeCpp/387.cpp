#include "stdafx.h"

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
*/
class Solution {
public:
	int firstUniqChar(string s) {
		if (s.empty()) return -1;

		int ret = -1;
		char tmp;
		vector<int> hash(26);
		for (int i = 0;i<s.size();i++)
		{
			hash[s[i] - 'a']++;
		}
		for (auto &it : s)
		{
			if (hash[it - 'a'] == 1)
			{
				ret = s.find(it);
				break;
			}
		}

		return ret;
	}
};

int test_387(string s)
{
	Solution so;
	int ret = so.firstUniqChar(s);
	return ret;
}
