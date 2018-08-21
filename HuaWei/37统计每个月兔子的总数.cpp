#include "stdafx.h"
#include "HuaWei.h"
#include <iostream>
using namespace std;

int test_37()
{
	int m;
	while (cin >> m)
	{
		//a:一个月兔子数，b：两个月兔子数，c：三个月兔子个数
		int a = 1, b = 0, c = 0;
		while (--m)
		{
			//每过一个月兔子数变化
			c += b;
			b = a;
			a = c;
		}
		cout << a + b + c << endl;
	}
	return 0;
}