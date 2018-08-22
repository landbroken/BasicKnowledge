#include "stdafx.h"

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/
class Solution {
public:
	bool isPalindrome(string s) {
		string tmp = "";
		for (int i = 0;i<s.size();i++)
		{
			if (isdigit(s[i]))
				tmp += s[i];
			else if (isupper(s[i]))
				tmp += s[i] - 'A' + 'a';
			else if (islower(s[i]))
				tmp += s[i];
		}
		if (tmp.size() <= 1) return true;

		int i = 0, j = tmp.size() - 1;
		while (i<j)
		{
			if (tmp[i++] != tmp[j--])
				return false;
		}
		return true;
	}
};