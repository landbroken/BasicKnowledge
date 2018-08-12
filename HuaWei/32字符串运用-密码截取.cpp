#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<string>
using namespace std;

int test_32()
{
	string str;
	while (cin >> str)
	{
		string newstr;
		for (int i = 0;i<str.size();i++)
		{
			newstr += '#';
			newstr += str[i];
		}
		newstr += '#';
		int max = 0;
		for (int i = 0;i<newstr.size();i++)
		{
			int count = 0;
			while (i - count >= 0 &&
				i + count <= newstr.size() &&
				newstr[i - count] == newstr[i + count]
				)
			{
				count++;
			}
			if (count - 1>max)
			{
				max = count - 1;
			}
		}
		cout << max << endl;
	}
	return 0;
}