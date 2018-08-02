#include "stdafx.h"
#include "HuaWei.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> G[105];

bool flag[105];
int pre[105];

bool dfs(int k) 
{
	int x;
	for (int i = 0;i<G[k].size();i++) 
	{
		x = G[k][i];
		if (flag[x]) continue;
		flag[x] = true;
		if ((pre[x] == 0) || dfs(pre[x])) 
		{
			pre[x] = k;
			return true;
		}
	}
	return false;
}

bool isprime[80000];
int nums[105];

int test_su_shu_ban_lv() 
{
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 4;i < 80000;i += 2)
	{
		isprime[i] = false;
	}
	for (int i = 3;i*i < 80000;i += 2)
	{
		if (isprime[i])
		{
			for (int j = i*i;j < 80000;j += 2 * i)
			{
				isprime[j] = false;
			}
		}
	}
	int n;
	while (cin>>n) 
	{
		for (int i = 1;i <= n;i++) 
		{
			cin >> nums[i];
		}
		for (int i = 1;i <= n;++i) 
		{
			for (int j = i + 1;j <= n;++j) 
			{
				if (isprime[nums[i] + nums[j]]) 
				{
					(nums[i] & 1) ? G[i].push_back(j) : G[j].push_back(i);
				}
			}
		}

		memset(pre, 0, sizeof(pre));
		int ans = 0;
		for (int i = 1;i <= n;i++) 
		{
			memset(flag, false, sizeof(flag));
			if (dfs(i)) ans++;
		}
		cout << ans << endl;

		for (int i = 1;i <= n;++i) 
		{
			G[i].clear();
		}
	}
	return 0;
}