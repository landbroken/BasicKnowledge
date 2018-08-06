#include"stdafx.h"
#include<string>
#include<iostream>
using namespace std;

int test_an_zi_jie_jie_qu_zi_fu_chuan()
{
	string str;
	int maxsize;
	while (cin >> str >> maxsize)
	{
		int realmax = 0;
		for (int i = 0;i<maxsize&&realmax <= maxsize;i++)
		{
			if (str[i]>127)
			{
				realmax += 2;
			}
			else
			{
				realmax += 1;
			}
			if (realmax>maxsize)
			{
				realmax -= 2;
				break;
			}
		}
		str = str.substr(0, realmax);
		cout << str;
		cout << endl;
	}
	return 0;
}