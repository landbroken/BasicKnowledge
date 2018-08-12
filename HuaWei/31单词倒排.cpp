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

int test_31()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> juzi;
		for (int i = 0;i<str.size();i++)
		{
			if (isalpha(str[i]))
			{
				string tmp;
				int j;
				for (j = i;j<str.size();j++)
				{
					if (isalpha(str[j]))
						tmp += str[j];

					else
						break;
				}
				juzi.push_back(tmp);
				i = j;
			}
		}

		for (int i = juzi.size() - 1;i >= 0;i--)
		{
			if (i>0)
				cout << juzi[i] << " ";
			if (i == 0)
				cout << juzi[i] << endl;
		}

	}
	return 0;
}