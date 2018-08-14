#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
using namespace std;

int test_38()
{
	int number;
	while (cin >> number)
	{
		cout << 2.875 * number << endl;
		cout << 0.03125 * number << endl;
	}
	return 0;
}