#include "stdafx.h"
#include "HuaWei.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool c_greater(const pair<int, string>&a, const pair<int, string>&b)
{
	return a.first>b.first;
}
bool c_less(const pair<int, string>&a, const pair<int, string>&b)
{
	return a.first<b.first;
}

int test_≥…º®≈≈–Ú()
{
	int n, flag;
	while (cin >> n >> flag)
	{
		string str;
		int score;
		vector<pair<int, string>> vec(n);
		// ‰»Î
		for (int i = 0;i<n;i++)
		{
			cin >> str >> score;
			vec[i].first = score;
			vec[i].second = str;
		}
		//≈≈–Ú
		if (flag == 0)
		{
			stable_sort(vec.begin(), vec.end(), c_greater);
		}
		else
		{
			stable_sort(vec.begin(), vec.end(), c_less);
		}
		// ‰≥ˆ
		for (int i = 0;i<vec.size();i++)
		{
			cout << vec[i].second << " " << vec[i].first << endl;
		}

	}
	return 0;
}