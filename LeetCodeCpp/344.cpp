#include "stdafx.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
请编写一个函数，其功能是将输入的字符串反转过来。

示例：

输入：s = "hello"
返回："olleh"
*/

class Solution {
public:
	string reverseString(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			char t = s[left];
			s[left++] = s[right];
			s[right--] = t;
		}
		return s;
	}
};