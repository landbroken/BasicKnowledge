#include "stdafx.h"

int test_41()
{
	int num;
	while (cin >> num)
	{
		//输入
		vector<int>m(num, 0);
		vector<int>x(num, 0);
		for (int i = 0;i < num;i++)
			cin >> m[i];
		for (int i = 0;i < num;i++)
			cin >> x[i];

		//最多有这么多种可能
		int allweight = 0;
		for (int i = 0;i < num;i++)
			allweight += m[i] * x[i];
		//储存已经遍历到的重量
		vector<int> temp(allweight + 1, 0);
		vector<int>weight;
		//对于只有1个砝码的情况
		for (int i = 0;i <= x[0];i++)
		{
			weight.push_back(i*m[0]);
			temp[i*m[0]] = 1;
		}
		//添加后续砝码
		//i是后续第mi个砝码
		//j是第i个砝码的数量
		//k是已经遍历过的重量
		for (int i = 1;i <num;i++)
		{
			int len = weight.size();
			for (int j = 0;j <= x[i];j++)
			{
				for (int k = 0;k < len;k++)
				{
					//cout << weight[k] + j*m[i] << endl;
					int curW = weight[k] + j*m[i];
					if (temp[curW] == 0)
					{
						weight.push_back(curW);
						temp[curW] = 1;
					}
				}
			}
		}

		cout << weight.size() << endl;
	}
	return 0;
}