#include "stdafx.h"
#include "HuaWei.h"
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;

int test_40()
{
	string str;
	while (getline(cin, str))
	{
		int English = 0, Blank = 0, Number = 0, Other = 0;
		for (int i = 0;i<str.size();i++)
		{
			char tmp = str[i];
			if (isalpha(tmp)) English++;
			else if (isblank(tmp)) Blank++;
			else if (isdigit(tmp)) Number++;
			else Other++;
		}
		cout << English << endl;
		cout << Blank << endl;
		cout << Number << endl;
		cout << Other << endl;
	}
	return 0;
}