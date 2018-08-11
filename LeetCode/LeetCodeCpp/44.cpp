#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输入: false
*/

class Solution {
public:
	
	/*
	直接循环判断，没有通过
	s="abefcdgiescdfimde"
    p="ab*cd?i*de"
	时不通过，应该匹配第二个cd不是第一个
	*/
	bool method1(string s, string p)
	{
		size_t i = 0;
		size_t j = 0;
		string ss, pp;
		bool flag_star = false;
		bool ret = true;
		while (i < s.size() && j<p.size())
		{
			//必定能匹配当前字符
			if ('?' == p[j])
			{
				i++;
				j++;
				flag_star = false;
			}
			//确定匹配到当前字符
			else if (s[i] == p[j])
			{
				i++;
				j++;
				flag_star = false;
			}
			//进入*匹配
			//**
			//*?
			//*
			//*a
			else if ('*' == p[j])
			{
				flag_star = true;
				//将**转为另外3种情况
				while ('*' == p[j])
				{
					j++;
				}
				if (j == p.size())
				{
					ret = true;
					return ret;
				}
			}
			else
			{
				if (flag_star)
				{
					i++;
					if (i == s.size())
					{
						ret = false;
						return ret;
					}
				}
				else
				{
					ret = false;
					return ret;
				}
			}
		}

		if (i<s.size())
		{
			ret = false;
			return ret;
		}

		while (j<p.size())
		{
			if (p[j] != '*')
			{
				return false;
			}
			j++;
		}

		return ret;
	}

	/*
	动态规划方法
	*/
	bool method2(string s, string p)
	{
		//p至少需要匹配到的字符长度=p长度-'*'数量
		int cnt_star=0;
		for (auto& it : p)
		{
			if (it == '*')
			{
				cnt_star++;
			}
		}
		if (p.size() - cnt_star > s.size())
			return false;

		vector<bool> vec_s(s.size() + 1);
		vector<vector<bool>> dp(p.size() + 1, vec_s);

		dp[0][0] = true;

		for (size_t i = 1; i <= p.size(); i++)
		{
			//设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
			dp[i][0] = dp[i - 1][0] && p[i - 1] == '*';
		}
		for (size_t j = 1; j <= s.size(); j++)
		{
			//第0行p为空，此时没有东西能匹配的上
			dp[0][j] = false;
		}

		for (size_t i = 1; i <= p.size(); i++)
		{
			for (size_t j = 1; j <= s.size(); j++)
			{
				if (s[j - 1] == p[i - 1]|| p[i - 1] == '?')
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[i-1]=='*')
				{
					//动态规划递推式（星号） 表示星号可以匹配
					//0个（决定于上次外循环的结果）或者
					//多个（决定于刚才内循环的结果）
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}

		return dp[p.size()][s.size()];
	}

	bool isMatch(string s, string p) 
	{
		return method2(s, p);
	}
};

bool test_44(string s, string p)
{
	Solution so;
	return so.isMatch(s, p);
}