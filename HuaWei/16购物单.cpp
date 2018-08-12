#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//商品
struct product_16
{
	int value; //价格
	int priority;//重要度
	int q;//编号，0为主件，非0为附件
};

static int GetMax(vector<product_16> &proVec,int N,int m)
{
	vector<int> dp(N + 1, 0);
	//01背包问题，建立一维表记录历史最优解
	for (int i = 1; i <= m; i++)
	{
		for (int j = N; j >= 10; j -= 10)
		{
			if (j >= proVec[i].value)
			{
				//如果为主件，取加入该主件和不加入该主件，价格*重要度的最大值
				if (proVec[i].q == 0)
				{
					int tmp = dp[j - proVec[i].value] + proVec[i].value * proVec[i].priority;
					dp[j] = max(dp[j], tmp);
				}
				else
				{
					//如果为非主件，同时也要加入相对应主件
					if (j >= proVec[i].value + proVec[proVec[i].q].value)
					{
						int tmp = dp[j - proVec[i].value -
							proVec[proVec[i].q].value] +
							proVec[i].value * proVec[i].priority +
							proVec[proVec[i].q].value * proVec[proVec[i].q].priority;
						dp[j] = max(dp[j], tmp);
					}
				}
			}
		}
	}
	return dp[N];
}

int test_16()
{
	int N, m;
	while (cin >> N >> m)
	{
		int v, p, q;
		int k0 = 0, k1 = 0;
		vector<product_16> proVec(60);
		int total;
		//输入全部
		for (int i = 1;i<=m;i++)
		{
			cin >> v >> p >> q;
			product_16 p16;
			p16.value = v;
			p16.priority = p;
			p16.q = q;
			proVec[i]=p16;
		}

		//规划
		int ret = GetMax(proVec, N, m);
		//输出
		cout << ret << endl;
	}
	return 0;
}