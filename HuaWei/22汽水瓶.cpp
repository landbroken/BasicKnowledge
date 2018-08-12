#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

int test_22()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int sum = 0;
		while (n >= 2)
		{
			if (n == 2)
			{
				sum++;
				break;
			}

			sum += n / 3;
			n = n / 3 + n % 3;
		}
		cout << sum << endl;
	}
	return 0;
}