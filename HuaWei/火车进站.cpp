#include "stdafx.h"
#include "HuaWei.h"
#include<stack>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
push:进站数量
pop：出栈数量
inCnt：剩余要进站数量
outCnt：剩余要出栈数量
*/
string foo(int push, int pop, int inCnt, int outCnt, int total)
{
	if (outCnt == total)
	{
		return 0;
	}
}

int test_火车进站()
{
	int N;
	while (cin >> N)
	{
		int tmp;
		vector<int> vec;
		for (int i = 0;i<N;i++)
		{
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end());



	}
	return 0;
}