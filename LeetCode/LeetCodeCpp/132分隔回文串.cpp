#include "stdafx.h"
/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

*/
/*
java版参考
public class Solution {
	public int minCut(String s) {
		int n = s.length();
		boolean[][] judge = new boolean[n][n];
		int[] dp = new int[n]; // dp[i]表示s中第i个字符到第（n-1）个字符所构成的子串的最小分割次数
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = Integer.MAX_VALUE;
			for (int j = i; j < n; j++) {
				if (s.charAt(i) == s.charAt(j) && (j - i <= 1 || judge[i + 1][j - 1])) {
					judge[i][j] = true;
					if (j + 1 < n) {
						dp[i] = Math.min(dp[i], 1 + dp[j + 1]);
					} else {
					dp[i] = 0;
					}
				}
			}
		}
	return dp[0];
	}
}

*/

class Solution {
public:
	int minCut(string s)
	{
		vector<vector<int>> dp;
		vector<int> temp;
		for (int i = 0;i<s.size();i++)
			temp.push_back(0);

		for (int i = 0;i<s.size();i++)
			dp.push_back(temp);

		vector<int> cut(s.size() + 1, 0);

		for (int i = s.size() - 1;i >= 0;i--)
		{
			cut[i] = INT_MAX;
			for (int j = i;j<s.size();j++)
			{
				if (s.at(i) == s.at(j) && (j - i <= 1 || dp[i + 1][j - 1] == 1))
				{
					dp[i][j] = 1;
					cut[i] = min(1 + cut[j + 1], cut[i]);
				}
			}
		}
		return cut[0] - 1;
	}
};
