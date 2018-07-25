// LeetCodeCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "LeetCodeCppTest.h"
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				char tmp = str[i] - 'A' + 'a';
				str.replace(i, 1, 1, tmp);
			}
		}
		return str;
	}
};

int main()
{
	test_537();
    return 0;
}

