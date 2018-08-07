#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
using namespace std;

/*
题目描述:
对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串。
定义ic，dc，rc分别为三种操作的代价，请设计一个高效算法，求出将A串变为B串所需要的最少代价。
给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300.
1
2
3
4
求解过程:
生成大小为(N+1)*(M+1)的矩阵dp. dp[x][y]表示A前x个字符串编辑成 B前y个字符所花费的代价.
对于第一行来说,dp[0][y]表示将一个空串变为B的前y个字符组成的子串,花费的代价为ic*y;
同理,对于第一列dp[x][0] = x*dc;

对于其他的位置,dp[x][y]可能有以下几种取值:
dp[x-1][y-1]+rc;//A[x-1]!=B[y-1] 将前x-1个字符变为B前y-1个字符,再将最后一个字符替换.
dp[x-1][y-1];//A[x-1]==B[y-1] 将前x-1个字符变为B前y-1个字符,最后一个不用修改.
dp[x-1][y]+dc;//删除一个字符,将前x-1个字符变为B的前y个字符
dp[x][y-1]+ic;//将A前x-1个字符变为B的前y个字符,再插入一个字符
dp[x][y]的值就为以上四者最小的一个.
求解完毕,dp[n][m]即为所求.
*/
class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int ic, int dc, int rc)
	{
		vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= m; ++i)
			dp[0][i] = ic*i;
		for (int i = 1; i <= n; ++i)
			dp[i][0] = dc*i;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int case1 = dp[i - 1][j] + dc;
				int case2 = dp[i][j - 1] + ic, case3 = dp[i - 1][j - 1];
				if (A[i - 1] != B[j - 1])
					case3 += rc;
				dp[i][j] = min(min(case1, case2), case3);
			}
		}
		return dp[n][m];
	}
};