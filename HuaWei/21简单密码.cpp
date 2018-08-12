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

string Upper2Pwd(const char& str)
{
	string ret;
	if (str >= 'A'&&str <= 'Y') ret = str - 'A' + 'a' + 1;
	else ret = 'a';
	return ret;
}

string Lower2Pwd(const char& str)
{
	string ret;
	if (str >= 'a'&&str <= 'c') ret = '2';
	else if (str >= 'd'&&str <= 'f') ret = '3';
	else if (str >= 'g'&&str <= 'i') ret = '4';
	else if (str >= 'j'&&str <= 'l') ret = '5';
	else if (str >= 'm'&&str <= 'o') ret = '6';
	else if (str >= 'p'&&str <= 's') ret = '7';
	else if (str >= 't'&&str <= 'v') ret = '8';
	else ret = '9';
	return ret;
}

int test_21()
{
	string str;
	while (cin >> str)
	{
		string tmp;
		for (int i = 0;i<str.size();i++)
		{
			if (str.at(i) >= 'a'&&str.at(i) <= 'z')
				tmp += Lower2Pwd(str.at(i));
			else if (str.at(i) >= 'A'&&str.at(i) <= 'Z')
				tmp += Upper2Pwd(str.at(i));
			else
				tmp += str.at(i);
		}
		cout << tmp << endl;
	}
	return 0;
}