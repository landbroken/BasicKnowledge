#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
#include <string>
#include <algorithm>
using  namespace std;

int test_34()
{
	string data;
	while (cin >> data)
	{
		sort(data.begin(), data.end());
		cout << data << endl;
	}
}