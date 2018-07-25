#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include "LeetCodeCppTest.h"
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int len = s.size();
		int ret = 0;
		//就是26进制[1,26]转10进制
		for (size_t i = 0; i < len; i++)
		{
			ret += (s[i] - 'A' + 1)*pow(26, len - i -1);
		}
		return ret;
	}
};