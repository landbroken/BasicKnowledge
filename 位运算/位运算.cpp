// 位运算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BitOperation.h"
#include<iostream>
using namespace std;

int main()
{
	//如果两个相应的二进制位都为１，则该位的结果值为1；否则为0。
	//11 & 3=3
	cout << (11 & 3) << endl;
	//如果两个相应的二进制位只要有一个是1，结果就是1；否则为0。
	//11 | 3 = 11
	cout << (11 | 3) << endl;
	//两个相同的数会变成0，反之是1
	//11^3 = 8
	cout << (11 ^ 3) << endl;
	cout << (~5) << endl;
    return 0;
}

