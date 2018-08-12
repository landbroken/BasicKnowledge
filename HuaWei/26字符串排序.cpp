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

int test_26()
{
	string str;
	while (getline(cin, str))
	{
		string english;
		for (int i = 0; i<str.size(); i++)//提取英文字母
			if (isalpha(str[i]))
				english += str[i];
		//对英文字母进行排序
		string english_sort;
		for (int i = 0; i<26; i++)
			for (int j = 0; j<english.size(); j++)
				if (english[j] - 'a' == i || english[j] - 'A' == i)
					english_sort += english[j];
		int tmp = 0;
		for (int i = 0; i<str.size(); i++)
			if (isalpha(str[i]))
			{
				str[i] = english_sort[tmp];
				tmp++;
			}
		cout << str << endl;
	}
	return 0;
}