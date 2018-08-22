#include "stdafx.h"

/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
示例 2:

输入: "abcd"
输出: "dcbabcd"

*/
/*
我们需要添加多少个字符与给定字符串的前缀子串回文的长度有关．
也就是说去掉其前缀的回文子串，我们只需要补充剩下的子串的逆序
就行了。
举个栗子：aacecaaa，其前缀的最大回文子串是aacecaa，剩下了一个a，
因此我们只需要在前面加上一个a的逆序a就行了。

KMP比较
*/
class Solution {
public:
	string shortestPalindrome(string s) {
		string str = s;
		reverse(str.begin(), str.end());
		str = s + "#" + str;
		int len1 = s.size(), len2 = str.size();
		vector<int> vec(len2, 0);

		for (int i = 1; i < len2; i++)
		{
			int k = vec[i - 1];
			while (k > 0 && str[k] != str[i])
				k = vec[k - 1];
			k += str[i] == str[k];
			vec[i] = k;
		}

		return str.substr(len1 + 1, len1 - vec[len2 - 1]) + s;
	}
};