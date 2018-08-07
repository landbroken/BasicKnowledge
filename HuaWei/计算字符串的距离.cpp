#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

int test_计算字符串的距离()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int n = str1.size(), m = str2.size();
		//dp[x][y]表示A前x个字符串编辑成 B前y个字符所花费的代价.
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

		//表示将一个空串变为B的前i个字符组成的子串
		for (int i = 0; i <= m; ++i)
			dp[i][0] = i;
		for (int i = 0; i <= n; ++i)
			dp[0][i] = i;

		//dp[x-1][y-1]+rc;//A[x-1]!=B[y-1] 将前x-1个字符变为B前y-1个字符,再将最后一个字符替换.
		//dp[x-1][y-1];//A[x-1]==B[y-1] 将前x-1个字符变为B前y-1个字符,最后一个不用修改.
		//dp[x-1][y]+dc;//删除一个字符,将前x-1个字符变为B的前y个字符
		//dp[x][y-1]+ic;//将A前x-1个字符变为B的前y个字符,再插入一个字符
		//dp[x][y]的值就为以上四者最小的一个.
		for (int i = 1;i <= m;++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int case1 = dp[i - 1][j - 1] + 1;
				int case2 = dp[i - 1][j - 1];
				int case3 = dp[i - 1][j] + 1;
				int case4 = dp[i][j - 1] + 1;
				if (str1[j - 1] == str2[i - 1])
					dp[i][j] = min(min(case3, case4), case2);
				else
					dp[i][j] = min(min(case3, case4), case1);
			}
		}
		cout << dp[m][n] << endl;
	}
	return 0;
}