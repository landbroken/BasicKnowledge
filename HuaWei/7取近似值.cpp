#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int test_7()
{
	double value;
	while (cin >> value)
	{
		value += 0.5;
		cout << floor(value) << endl;
	}
	return 0;
}