// STL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<vector<int>> arr;
	const int raw_len = 3;
	const int column_len = 4;
	int a[raw_len*column_len] = {
		1,2,3,4,
		5,6,7,8,
		9,10,11,12
	};
	int* data = a;
	arr.resize(raw_len);
	for (size_t i = 0; i < raw_len; i++)
	{
		for (size_t j = 0; j < column_len; j++)
		{
			arr[i].push_back(data[i*column_len + j]);
		}
	}
    return 0;
}

