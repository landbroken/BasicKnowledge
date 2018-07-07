#include"stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

class VectorDemo
{
public:
	VectorDemo();
	~VectorDemo();

	void Add(int* data, int raw_len, int column_len);
	//遍历二维数组
	void ErgodicOutput();

private:
	vector<vector<int>> arr;
};

VectorDemo::VectorDemo()
{
}

VectorDemo::~VectorDemo()
{
}

void VectorDemo::Add(int* data,int raw_len,int column_len)
{
	for (size_t i = 0; i < raw_len; i++)
	{
		for (size_t j = 0; j < column_len; j++)
		{
			arr[i].push_back(data[i*column_len +j]);
		}
	}
}

void VectorDemo::ErgodicOutput()
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[0].size();j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}