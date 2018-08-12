#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int test_8()
{
	int n;
	while (cin >> n)
	{
		int iKey, iValue;
		map<int, int> mMap;
		for (int i = 0;i<n;i++)
		{
			cin >> iKey >> iValue;
			mMap[iKey] += iValue;
		}
		for (auto i = mMap.begin();i != mMap.end();++i)
		{
			cout << i->first << " " << i->second << endl;
		}
	}
	return 0;
}