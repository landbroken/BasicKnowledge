#include"stdafx.h"

int test_45()
{
	int N;
	while (cin >> N)
	{
		string str;
		vector<string> vec;
		vector<vector<int>> ivec(N);
		for (int i = 0;i<N;i++)
		{
			cin >> str;
			vec.push_back(str);
			ivec[i].resize(26);
			//统计重复个数
			for (int j = 0;j<str.size();j++)
			{
				int tmp;
				if (str[j] >= 'a'&&str[j] <= 'z')
					tmp = str[j] - 'a';
				else
					tmp = str[j] - 'A';
				ivec[i][tmp]++;
			}
			sort(ivec[i].rbegin(), ivec[i].rend());
		}

		//i循环名字
		for (int i = 0;i<vec.size();i++)
		{
			//j循环求名字内重复数量
			int nmax = 26;
			int sum = 0;
			for (int j = 0;j<ivec[i].size();j++)
			{
				if (ivec[i][j] == 0)
					break;
				sum += nmax*ivec[i][j];
				nmax--;
			}
			cout << sum << endl;
		}
	}
	return 0;
}