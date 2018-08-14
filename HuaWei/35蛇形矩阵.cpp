#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
using namespace std;

int test_35()
{
	int Num;
	while (cin >> Num)
	{
		int head = 1;
		for (int i = 0; i<Num; i++)
		{
			head += i;
			int before = head;
			cout << head;
			if (i == Num - 1)
			{
				cout << endl;
			}
			int interval = i + 2;
			int row = Num - i;
			for (int j = 1; j<row; j++)
			{
				if (j != row - 1)
				{
					cout << " " << before + interval;
					before += interval;
					interval++;
				}
				else
				{
					cout << " " << before + interval << endl;
				}
			}
		}
	}
	return 0;
}