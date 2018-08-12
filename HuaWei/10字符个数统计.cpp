#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int test_10()
{
	string str;
	while (cin >> str)
	{
		int sum = 0;
		set<char> s(str.begin(), str.end());
		cout << s.size() << endl;
	}
	return 0;
}