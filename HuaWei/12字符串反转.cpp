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

void method_1(string str)
{
	int size = str.size();
	for (int i = 0;i<size;i++)
	{
		cout << str[size - i - 1];
	}
	cout << endl;
}

void method_2(string str)
{
	reverse(str.begin(), str.end());
	cout << str << endl;
}

int test_12()
{
	string str;
	while (cin >> str)
	{
		method_2(str);
	}
	return 0;
}