#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<string>
using namespace std;

int test_1()
{
	string str;
	getline(cin, str);
	int end = str.find_last_of(' ');
	string last(str, end + 1, str.size() - end);
	cout << last.size();

	return 0;
}