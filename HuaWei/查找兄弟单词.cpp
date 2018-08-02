#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

bool comparestr(string s1, string s2)
{
	if (s1 == s2)
	{
		return false;
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int test_cha_zhao_xiong_di_dan_ci()
{
	int num;
	string str[1000];
	vector<string>vec;
	vector<string>::iterator it;
	while (cin >> num)
	{
		int i = 0, j = 0, icount = 0, index, k = 1;
		string searchword, str, indexword;
		vec.clear();
		for (i = 0;i<num;i++)
		{
			cin >> str;
			vec.push_back(str);
		}
		sort(vec.begin(), vec.end());
		cin >> searchword;
		cin >> index;

		for (i = 0;i<num;i++)
		{
			if (comparestr(vec[i], searchword))
			{
				icount++;

				if (icount == index)
				{
					indexword = vec[i];
				}
			}
		}
		if (!vec.empty())
		{
			cout << icount << endl;
		}
		if (icount >= index)
		{
			cout << indexword << endl;
		}
	}
	return 0;
}