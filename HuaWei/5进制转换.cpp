#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<set>
#include<string>
using namespace std;

int test_5()
{
	string str;
	string str_dec;
	int decimal = 0;
	int flag = 1;
	while (cin >> str)
	{
		char *offset;
		//strtol和stol这两种都行
		int ret = strtol(str.c_str(), &offset, 16);
		cout << ret << endl;
		//int ret2=stol(str,nullptr,16);
		//cout<<ret2<<endl;
	}
	return 0;
}