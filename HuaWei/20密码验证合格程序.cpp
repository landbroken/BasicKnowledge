#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

bool isAtLeastThree(const string& str)
{
	bool lower = false, upper = false, nums = false, other = false;
	for (int i = 0;i<str.size();i++)
	{
		//if (str.at(i) >= 'a'&&str.at(i) <= 'z') lower = true;
		//else if (str.at(i) >= 'A'&&str.at(i) <= 'Z') upper = true;
		//else if (str.at(i) >= '0'&&str.at(i) <= '9') nums = true;
		if (islower(str[i])) lower = true;
		else if (isupper(str[i])) upper = true;
		else if (isdigit(str[i])) nums = true;
		else other = true;
	}
	return (lower + upper + nums + other) >= 3;
}

bool isSameMoreTwo(const string& str)
{
	for (int i = 0; i <= str.size() - 6; i++)
	{
		for (int j = i + 3;j < str.size();j++)
		{
			if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
			{
				return false;
			}
		}
	}
	return true;
}

int test_20()
{
	string str;
	while (getline(cin, str))
	{
		bool is_ok = true;
		if (str.size() <= 8) is_ok = false;
		else if (!isAtLeastThree(str)) is_ok = false;
		else if (!isSameMoreTwo(str)) is_ok = false;
		if (is_ok)
			cout << "OK" << endl;
		else
			cout << "NG" << endl;
	}
	return 0;
}