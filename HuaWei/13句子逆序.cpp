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
	string tmp;
	int space = str.find_last_of(" ");
	while (space>0)
	{
		tmp = str.substr(space + 1, str.size() - space - 1);
		cout << tmp << " ";
		str = str.substr(0, space);
		space = str.find_last_of(" ");
	}
	cout << str << endl;
}

void method_2(string str)
{
	string tmp = "";
	vector<string> vec;
	for (int i = 0;i<str.size();i++)
	{
		if (str[i] == ' ')
		{
			vec.push_back(tmp);
			tmp.clear();
		}
		else
		{
			tmp += str[i];
		}
	}
	vec.push_back(tmp);

	for (auto it = vec.rbegin();it != vec.rend();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int test_13()
{
	string str;
	while (getline(cin, str))
	{
		method_1(str);
	}
	return 0;
}