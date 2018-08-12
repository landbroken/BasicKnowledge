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

int test_23()
{
	string str;
	while (cin >> str)
	{
		int cnt[26] = { 0 };
		int min;
		string ret = "";
		//统计
		for (int i = 0;i<str.size();i++)
		{
			int tmp = str[i] - 'a';
			cnt[tmp]++;
			min = cnt[tmp];
		}
		for (int i = 0;i<26;i++)
		{
			if (cnt[i] >= 1)
				min = min <= cnt[i] ? min : cnt[i];
		}
		//删除
		for (int i = 0;i<str.size();i++)
		{
			//写法一，原位置删除
			//if(cnt[str[i]-'a']==min)
			//{
			//    str=str.substr(0,i)+str.substr(i+1,str.size()-i-1);
			//    i--;
			//}
			//写法二，用一个新变量保存结果
			int tmp = str[i] - 'a';
			if (cnt[tmp] != min&&cnt[tmp]>0)
			{
				ret += str[i];
			}
		}
		cout << ret << endl;
	}
	return 0;
}