#include "stdafx.h"
#include "HuaWei.h"
#include<iostream>
#include<set>
#include<string>
using namespace std;

int test_3()
{
	int num = 0;
	while (cin >> num)
	{
		int value;
		set<int> iset;
		for (int i = 0; i<num; i++)
		{
			cin >> value;
			iset.insert(value);
		}
		for (auto m = iset.begin();m != iset.end();m++)
		{
			cout << *m << endl;
		}
	}
	return 0;
}