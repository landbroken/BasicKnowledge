#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
using namespace std;

int test_33()
{
	long long n, a1, a2, a3, a4;
	char ch;
	while (cin >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4)
	{
		cin >> n;
		long long inter = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
		a1 = n >> 24;
		a2 = (n >> 16) & 255;
		a3 = (n >> 8) & 255;
		a4 = n & 255;
		cout << inter << endl;
		cout << a1 << "." << a2 << "." << a3 << "." << a4 << endl;
	}
	return 0;
}