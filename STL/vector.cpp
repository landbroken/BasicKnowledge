#include"stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

class VectorDemo
{
public:
	VectorDemo();
	~VectorDemo();

	//初始化vector
	void Initial();
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

void VectorDemo::Initial()
{
	//1)不带参数的构造函数初始化
	//初始化一个size为0的vector
	vector<int> a;

	//2)带参数的构造函数初始化
	//初始化size,但每个元素值为默认值
	//初始化了10个默认值为0的元素
	vector<int> b(10);    
	//初始化size,并且设置初始值
	//初始化了10个值为1的元素
	vector<int> c(10,1);

	//3)通过数组地址初始化
	int d[5] = { 1,2,3,4,5 };
	//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
	vector<int> e(d, d + 5);

	//4)通过同类型的vector初始化
	vector<int> f(5, 1);
	//通过a初始化
	vector<int> g(f);

	//5)通过insert初始化
	//insert初始化方式将同类型的迭代器对应的始末区间（左闭右开区间）内的值插入到vector中
	vector<int> a5(6, 6);
	vector<int> b5;
	//将a[0]~a[2]插入到b中，b.size()由0变为3
	b5.insert(b5.begin(), a5.begin(), a5.begin() + 3);

	//insert也可通过数组地址区间实现插入
	int a5_2[6] = { 6,6,6,6,6,6 };
	//将a的所有元素插入到b中
	b5.insert(b5.begin(), a5_2, a5_2 + 7);

	//此外，insert还可以插入m个值为n的元素
	//在b开始位置处插入6个6
	b5.insert(b5.begin(), 6, 6);

	//6)通过copy函数赋值
	vector<int> a6(5, 1);
	int a6_2[5] = { 2,2,2,2,2 };
	vector<int> b6(10);

	/*将a中元素全部拷贝到b开始的位置中,注意拷贝的区间为a.begin() ~ a.end()的左闭右开的区间*/
	copy(a6.begin(), a6.end(), b6.begin());

	//拷贝区间也可以是数组地址构成的区间
	copy(a6_2, a6_2 + 5, b6.begin() + 5);
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