#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void CountOne(int n)
{
	int sum = 0;
	while (n != 0)
	{
		if (n & 1) sum++;
		n = n >> 1;
	}
	cout << sum;
}

int test_15()
{
	int n;
	while (cin >> n)
	{
		CountOne(n);
	}
	return 0;
}
