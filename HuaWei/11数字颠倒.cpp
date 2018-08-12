#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int test_11()
{
	string str;
	while (cin >> str)
	{
		int size = str.size();
		for (int i = 0;i<size;i++)
		{
			cout << str[size - i - 1];
		}
		cout << endl;
	}
	return 0;
}