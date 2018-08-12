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

int charToInt(char c) {
	return c - '0';
}

string add(string _s1, string _s2) {
	string sumStr = "";
	string s1 = _s1, s2 = _s2;
	int p;
	int carry = 0;
	int temp = 0;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int pMax = s1.length() > s2.length() ? s2.length() : s1.length();
	//两个都有的位置
	for (p = 0; p < pMax; p++)
	{
		temp = charToInt(s1[p]) + charToInt(s2[p]) + carry;
		carry = temp / 10;
		sumStr += to_string(temp % 10);
	}
	//处理较大数多余部分
	if (p < s1.length())
	{
		for (; p < s1.length(); p++)
		{
			temp = charToInt(s1[p]) + carry;
			carry = temp / 10;
			sumStr += to_string(temp % 10);
		}
	}
	if (p < s2.length())
	{
		for (; p < s2.length(); p++)
		{
			temp = charToInt(s2[p]) + carry;
			carry = temp / 10;
			sumStr += to_string(temp % 10);
		}
	}
	//两个数位数一样时，处理最后一个进位
	if (carry > 0)
	{
		sumStr += to_string(carry % 10);
		carry /= 10;
	}

	reverse(sumStr.begin(), sumStr.end());

	return sumStr;
}

int test_高精度整数加法()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		string result;
		result = add(str1, str2);
		cout << result << endl;
	}
	return 0;
}