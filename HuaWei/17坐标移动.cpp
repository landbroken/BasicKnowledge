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

int test_17()
{
	string str;
	while (cin >> str)
	{
		int x = 0, y = 0;
		while (str.size()>1)
		{
			int sep = str.find(";");
			string tmp = str.substr(1, sep - 1);
			if (tmp.size() == 1 || tmp.size() == 2)
			{
				char *offset;
				int inext = strtol(tmp.c_str(), &offset, 10);
				switch (str[0]) {
				case 'A':
					x -= inext;
					break;
				case 'D':
					x += inext;
					break;
				case 'W':
					y += inext;
					break;
				case 'S':
					y -= inext;
					break;
				default:
					break;
				}
			}
			str = str.substr(sep + 1, str.size() - sep - 1);
		}
		cout << x << "," << y << endl;
	}
	return 0;
}