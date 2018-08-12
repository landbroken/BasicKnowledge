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

bool compare(const string& a, const string& b)
{
	return a<b;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vec;
		string tmp;
		for (int i = 0;i<n;i++)
		{
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end(), compare);
		for (auto it = vec.begin();it != vec.end();it++)
		{
			cout << *it << endl;
		}
	}
	return 0;
}