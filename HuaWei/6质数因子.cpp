#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

int test_6()
{
	long data;
	while (cin >> data)
	{
		string ret;
		long tmp = data;
		while (tmp != 1)
		{
			for (int i = 2;i <= tmp;i++)
			{
				if (tmp%i == 0)
				{
					ret += to_string(i);
					ret += " ";
					tmp /= i;
					break;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}