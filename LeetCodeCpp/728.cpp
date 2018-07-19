#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ret;
		for (size_t i = left; i <= right; i++)
		{
			int tmp = i;
			bool flag = true;
			while (tmp != 0)
			{
				//最后一位数
				int a = tmp % 10;
				//a为0，分母为0，除不尽
				if (a==0 || i%a!=0)
				{
					flag = false;
					break;
				}
				tmp = tmp / 10;
			}
			if (flag)
			{
				ret.push_back(i);
			}
		}
		return ret;
	}
};