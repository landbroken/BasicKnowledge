#include "stdafx.h"

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/
class Solution {
public:
	/*排序后相等，o(nlogn)*/
	bool method_1(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}

	/*计数判相等,o(n)*/
	bool method_2(string s, string t)
	{
		if (s.size() != t.size())
			return false;

		vector<int> vec(26, 0);
		for (int i = 0;i<s.size();i++)
		{
			vec[s[i] - 'a']++;
			vec[t[i] - 'a']--;
		}
		for (int i = 0;i<vec.size();i++)
		{
			if (vec[i] != 0)
			{
				return false;
			}
		}

		return true;
	}

	bool isAnagram(string s, string t) {
		return method_2(s, t);
	}
};