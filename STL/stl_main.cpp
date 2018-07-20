// STL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include"stl_demo.h"
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

	//初始化，插入，修改
	const int arrvec[4] = { 3,2,2,2 };
	int arrvec2[4];
	std::vector<int> vec(3, 1);//1,1,1
	vec.insert(vec.begin(), 2);//2,1,1,1
	std::vector<int>::iterator it=vec.begin();
	for (size_t i = 0; i < sizeof(arrvec2) / sizeof(int); i++)
	{
		(*it)++;
		arrvec2[i] = *it;
		it++;
	}

	MapDemo m;
	m.Insert();
	m.Output();

    return 0;
}

