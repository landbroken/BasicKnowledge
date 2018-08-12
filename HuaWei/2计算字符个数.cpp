#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<string>
using namespace std;

int test_2()
{
	string str;
	char up;
	char low;
	cin >> str >> up;
	int sum = 0;

	if (up >= 'A'&&up <= 'Z')
	{
		low = up - 'A' + 'a';
	}
	else
	{
		low = up;
		up = up - 'a' + 'A';
	}

	for (int i = 0;i<str.size();i++)
	{
		if (str.at(i) == up) sum++;
		else if (str.at(i) == low) sum++;
	}
	cout << sum;

	return 0;
}